#include "dython.h"

static dds_condition_t gc;

static void publication_matched_handler 
  (dds_entity_t writer, dds_publication_matched_status_t * status)
{
  printf ("publication matched...\n");
  printf ("total count = %d\n", status->total_count);
  printf ("total count change = %d\n", status->total_count_change);
  printf ("current count = %d\n", status->current_count);
  printf ("current count change = %d\n", status->current_count_change);
  dds_guard_trigger (gc);
}

/* Simple publisher */

int main (int argc, char ** argv)
{
  int status;
  dds_qos_t * qos = NULL;
  dds_entity_t ppant;
  dds_entity_t topic;
  dds_entity_t pub;
  dds_entity_t writer;
  dds_waitset_t pms;
  dds_duration_t timeout = DDS_INFINITY;
  dds_writerlistener_t wr_listener;

  /* Topic instance */

  dython_bit_KDython sample = { "Key", "Value" };

  /* Initialize DDS */

  status = dds_init (argc, argv);
  DDS_ERR_CHECK (status, DDS_CHECK_REPORT | DDS_CHECK_EXIT);

  /* Create participant */

  status = dds_participant_create (&ppant, DDS_DOMAIN_DEFAULT, qos, NULL);
  DDS_ERR_CHECK (status, DDS_CHECK_REPORT | DDS_CHECK_EXIT);

  /* Create topic */

  status = dds_topic_create (ppant, &topic, &dython_bit_KDython_desc, "KeyValue", qos, NULL);

  DDS_ERR_CHECK (status, DDS_CHECK_REPORT | DDS_CHECK_EXIT);

  /* Create publisher */

  status = dds_publisher_create (ppant, &pub, qos, NULL);
  DDS_ERR_CHECK (status, DDS_CHECK_REPORT | DDS_CHECK_EXIT);

  /* Create writer with QoS */

  qos = dds_qos_create ();
  dds_qset_durability (qos, DDS_DURABILITY_VOLATILE);

  /* Create a listener with a callback handler for publication_matched status */

  memset (&wr_listener, 0, sizeof (wr_listener));
  wr_listener.on_publication_matched = publication_matched_handler;

  status = dds_writer_create (pub, &writer, topic, NULL, &wr_listener);
  DDS_ERR_CHECK (status, DDS_CHECK_REPORT | DDS_CHECK_EXIT);
  dds_qos_delete (qos);

  pms = dds_waitset_create ();
  gc = dds_guardcondition_create ();
  status = dds_waitset_attach (pms, gc, writer);
  DDS_ERR_CHECK (status, DDS_CHECK_REPORT | DDS_CHECK_EXIT);

  printf ("Waiting for Reader to start...\n");
  fflush (stdout);
  status = dds_waitset_wait (pms, 0, 0, timeout);
  DDS_ERR_CHECK (status, DDS_CHECK_REPORT | DDS_CHECK_EXIT);

  printf ("Reader found, write data ...\n");
  
  /* Write topic */

  status = dds_write (writer, &sample);
  DDS_ERR_CHECK (status, DDS_CHECK_REPORT | DDS_CHECK_EXIT);

  printf ("Waiting for Reader to cease ... \n");
  status = dds_waitset_wait (pms, 0, 0, timeout);
  DDS_ERR_CHECK (status, DDS_CHECK_REPORT | DDS_CHECK_EXIT);

  /* Clean up */

  dds_sleepfor (DDS_MSECS (500));
  dds_condition_delete (gc);
  status = dds_waitset_delete (pms);
  DDS_ERR_CHECK (status, DDS_CHECK_REPORT | DDS_CHECK_EXIT);
  dds_entity_delete  (ppant);
  dds_fini ();
}
