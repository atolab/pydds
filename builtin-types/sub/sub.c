#include "dython.h"

/*
 * Simple subscriber using a listener function which is called when
 * data is available. A guard condition is used for synchronisation
 * between the listener thread and the main thread.
 */

static dds_condition_t gc;

/*
 * The data available handler. This is called when data is available
 * for processing. It prints the data, then tells the main thread that
 * it is finished.
 */

#define max_samples 1

static void data_available_handler (dds_entity_t reader)
{
  printf("data-available... \n");
  int ret;
  dds_sample_info_t info[max_samples];
  void * samples[max_samples];
  uint32_t mask = 0;


  samples[0] = NULL; //&sample;
  //  samples[0] = &sample;
  /* Set type of samples required. */

  mask = DDS_ALIVE_INSTANCE_STATE;

  /* Read samples. */
  printf("Going to read data!");
  ret = dds_read (reader, samples, 1, info, mask);

  dython_bit_KDython*  psample = (dython_bit_KDython*)samples[0];
  /* Print sample */

  if (DDS_ERR_CHECK (ret, DDS_CHECK_REPORT))
    {
      printf ("Data Received ...\n");
      printf ("Sample (%s, %s)\n", psample->key, psample->value);
      
      // Trigger the guard condition. This informs the main thread that
      //      the data has been handled.
      
      dds_guard_trigger (gc);
  }
}

/*
 * The main function initialises the necessary entities, registers a
 * listener with the reader and attaches a guard condition to a
 * waitset. It then waits on the waitset until the listener
 * triggers the guard condition to indicate that it has handled the
 * data. After this, it cleans up and terminates.
 */

int main (int argc, char ** argv)
{
  int ret;
  dds_qos_t * qos = NULL;
  dds_entity_t ppant;
  dds_entity_t topic;
  dds_entity_t sub;
  dds_entity_t reader;
  dds_duration_t timeout = DDS_INFINITY;
  dds_waitset_t ws;
  dds_readerlistener_t listener;
  dds_attach_t wsresults[1];
  size_t wsresultsize = 1U;

  /* Initialize DDS. */

  ret = dds_init (argc, argv);
  DDS_ERR_CHECK (ret, DDS_CHECK_REPORT | DDS_CHECK_EXIT);

  /* Create participant. */

  ret = dds_participant_create (&ppant, DDS_DOMAIN_DEFAULT, qos, NULL);
  DDS_ERR_CHECK (ret, DDS_CHECK_REPORT | DDS_CHECK_EXIT);

  /* Create topic. */

  ret = dds_topic_create (ppant, &topic, &dython_bit_KDython_desc, "KeyValue", qos, NULL);
  DDS_ERR_CHECK (ret, DDS_CHECK_REPORT | DDS_CHECK_EXIT);

  /* Create subscriber. */

  ret = dds_subscriber_create (ppant, &sub, qos, NULL);
  DDS_ERR_CHECK (ret, DDS_CHECK_REPORT | DDS_CHECK_EXIT);

  /*
   * Create a waitset and attach a guard condition. The condition will
   * be triggered by the listener function after it has handled the
   * data.
   */

  ws = dds_waitset_create ();
  gc = dds_guardcondition_create ();
  ret = dds_waitset_attach (ws, gc, NULL);
  DDS_ERR_CHECK (ret, DDS_CHECK_REPORT | DDS_CHECK_EXIT);

  /*
   * Create a listener which has the 'on_data_available' member set to
   * the data available handler function defined above. 
   */

  memset (&listener, 0, sizeof (listener));
  listener.on_data_available = data_available_handler;

  /* Cretae reader with DATA_AVAILABLE status condition enabled */

  /* qos = dds_qos_create (); */
  /* dds_qset_reliability (qos, DDS_RELIABILITY_RELIABLE, DDS_SECS (1)); */
  /* dds_qset_history (qos, DDS_HISTORY_KEEP_ALL, 0); */

  ret = dds_reader_create (sub, &reader, topic, NULL, &listener);
  DDS_ERR_CHECK (ret, DDS_CHECK_REPORT | DDS_CHECK_EXIT);
  dds_qos_delete (qos);

  /*
   * Wait until the listener has handled the data. There is only one
   * condition in the waitset, so no real need to determine which
   * condition has triggered. 
   */
 
  ret = dds_waitset_wait (ws, wsresults, wsresultsize, timeout);
  DDS_ERR_CHECK (ret, DDS_CHECK_REPORT | DDS_CHECK_EXIT);

  /* Disable callbacks */

  dds_status_set_enabled (reader, 0);

  /* Clean up. The call to dds_entity_delete() will delete the
   * participant and all the entities that it contains, i.e. the
   * topic, the subscriber, and the reader.
   */

  dds_condition_delete (gc);
  ret = dds_waitset_delete (ws);
  DDS_ERR_CHECK (ret, DDS_CHECK_REPORT | DDS_CHECK_EXIT);

  dds_entity_delete (ppant);
  dds_fini ();
}
