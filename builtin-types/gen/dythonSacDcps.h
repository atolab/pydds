#ifndef DYTHONSACDCPS_H
#define DYTHONSACDCPS_H

#include "dds_dcps.h"
#include "dythonDcps.h"

#ifndef DDS_API
#define DDS_API
#endif


#define dython_bit_KDythonTypeSupport DDS_TypeSupport

 dython_bit_KDythonTypeSupport
dython_bit_KDythonTypeSupport__alloc (
    void
    );

 DDS_ReturnCode_t
dython_bit_KDythonTypeSupport_register_type (
    dython_bit_KDythonTypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

 DDS_string
dython_bit_KDythonTypeSupport_get_type_name (
    dython_bit_KDythonTypeSupport _this
    );

#ifndef _DDS_sequence_dython_bit_KDython_defined
#define _DDS_sequence_dython_bit_KDython_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    dython_bit_KDython *_buffer;
    DDS_boolean _release;
} DDS_sequence_dython_bit_KDython;

 DDS_sequence_dython_bit_KDython *DDS_sequence_dython_bit_KDython__alloc (void);
 dython_bit_KDython *DDS_sequence_dython_bit_KDython_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_dython_bit_KDython_defined */

#define dython_bit_KDythonDataWriter DDS_DataWriter

#define dython_bit_KDythonDataWriter_enable DDS_Entity_enable

#define dython_bit_KDythonDataWriter_get_status_changes DDS_Entity_get_status_changes

#define dython_bit_KDythonDataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define dython_bit_KDythonDataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define dython_bit_KDythonDataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define dython_bit_KDythonDataWriter_get_listener DDS_DataWriter_get_listener

#define dython_bit_KDythonDataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define dython_bit_KDythonDataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define dython_bit_KDythonDataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define dython_bit_KDythonDataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define dython_bit_KDythonDataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define dython_bit_KDythonDataWriter_get_publication_matched_status DDS_DataWriter_get_publication_matched_status

#define dython_bit_KDythonDataWriter_get_publisher DDS_DataWriter_get_publisher

#define dython_bit_KDythonDataWriter_get_qos DDS_DataWriter_get_qos

#define dython_bit_KDythonDataWriter_get_topic DDS_DataWriter_get_topic

#define dython_bit_KDythonDataWriter_set_listener DDS_DataWriter_set_listener

#define dython_bit_KDythonDataWriter_set_qos DDS_DataWriter_set_qos

 DDS_InstanceHandle_t
dython_bit_KDythonDataWriter_register_instance (
    dython_bit_KDythonDataWriter _this,
    const dython_bit_KDython *instance_data
    );

 DDS_InstanceHandle_t
dython_bit_KDythonDataWriter_register_instance_w_timestamp (
    dython_bit_KDythonDataWriter _this,
    const dython_bit_KDython *instance_data,
    const DDS_Time_t *source_timestamp
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataWriter_unregister_instance (
    dython_bit_KDythonDataWriter _this,
    const dython_bit_KDython *instance_data,
    const DDS_InstanceHandle_t handle
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataWriter_unregister_instance_w_timestamp (
    dython_bit_KDythonDataWriter _this,
    const dython_bit_KDython *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataWriter_write (
    dython_bit_KDythonDataWriter _this,
    const dython_bit_KDython *instance_data,
    const DDS_InstanceHandle_t handle
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataWriter_write_w_timestamp (
    dython_bit_KDythonDataWriter _this,
    const dython_bit_KDython *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataWriter_dispose (
    dython_bit_KDythonDataWriter _this,
    const dython_bit_KDython *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataWriter_dispose_w_timestamp (
    dython_bit_KDythonDataWriter _this,
    const dython_bit_KDython *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataWriter_writedispose (
    dython_bit_KDythonDataWriter _this,
    const dython_bit_KDython *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataWriter_writedispose_w_timestamp (
    dython_bit_KDythonDataWriter _this,
    const dython_bit_KDython *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataWriter_get_key_value (
    dython_bit_KDythonDataWriter _this,
    dython_bit_KDython *key_holder,
    const DDS_InstanceHandle_t handle
    );

 DDS_InstanceHandle_t
dython_bit_KDythonDataWriter_lookup_instance (
    dython_bit_KDythonDataWriter _this,
    const dython_bit_KDython *key_holder
    );

#define dython_bit_KDythonDataReader DDS_DataReader

#define dython_bit_KDythonDataReader_enable DDS_Entity_enable

#define dython_bit_KDythonDataReader_get_status_changes DDS_Entity_get_status_changes

#define dython_bit_KDythonDataReader_get_statuscondition DDS_Entity_get_statuscondition

#define dython_bit_KDythonDataReader_get_instance_handle DDS_Entity_get_instance_handle

#define dython_bit_KDythonDataReader_create_querycondition DDS_DataReader_create_querycondition

#define dython_bit_KDythonDataReader_create_readcondition DDS_DataReader_create_readcondition

#define dython_bit_KDythonDataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define dython_bit_KDythonDataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define dython_bit_KDythonDataReader_get_listener DDS_DataReader_get_listener

#define dython_bit_KDythonDataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define dython_bit_KDythonDataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define dython_bit_KDythonDataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define dython_bit_KDythonDataReader_get_qos DDS_DataReader_get_qos

#define dython_bit_KDythonDataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define dython_bit_KDythonDataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define dython_bit_KDythonDataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define dython_bit_KDythonDataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define dython_bit_KDythonDataReader_get_subscriber DDS_DataReader_get_subscriber

#define dython_bit_KDythonDataReader_get_subscription_matched_status DDS_DataReader_get_subscription_matched_status

#define dython_bit_KDythonDataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define dython_bit_KDythonDataReader_set_listener DDS_DataReader_set_listener

#define dython_bit_KDythonDataReader_set_qos DDS_DataReader_set_qos

#define dython_bit_KDythonDataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

 DDS_ReturnCode_t
dython_bit_KDythonDataReader_read (
    dython_bit_KDythonDataReader _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataReader_take (
    dython_bit_KDythonDataReader _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataReader_read_w_condition (
    dython_bit_KDythonDataReader _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataReader_take_w_condition (
    dython_bit_KDythonDataReader _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataReader_read_next_sample (
    dython_bit_KDythonDataReader _this,
    dython_bit_KDython *received_data,
    DDS_SampleInfo *sample_info
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataReader_take_next_sample (
    dython_bit_KDythonDataReader _this,
    dython_bit_KDython *received_data,
    DDS_SampleInfo *sample_info
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataReader_read_instance (
    dython_bit_KDythonDataReader _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataReader_take_instance (
    dython_bit_KDythonDataReader _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataReader_read_next_instance (
    dython_bit_KDythonDataReader _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataReader_take_next_instance (
    dython_bit_KDythonDataReader _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataReader_read_next_instance_w_condition (
    dython_bit_KDythonDataReader _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataReader_take_next_instance_w_condition (
    dython_bit_KDythonDataReader _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataReader_return_loan (
    dython_bit_KDythonDataReader _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataReader_get_key_value (
    dython_bit_KDythonDataReader _this,
    dython_bit_KDython *key_holder,
    const DDS_InstanceHandle_t handle
    );

 DDS_InstanceHandle_t
dython_bit_KDythonDataReader_lookup_instance (
    dython_bit_KDythonDataReader _this,
    const dython_bit_KDython *key_holder
    );

#define dython_bit_KDythonDataReaderView DDS_DataReaderView

#define dython_bit_KDythonDataReaderView_enable DDS_Entity_enable

#define dython_bit_KDythonDataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define dython_bit_KDythonDataReaderView_get_qos DDS_DataReaderView_get_qos

#define dython_bit_KDythonDataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define dython_bit_KDythonDataReaderView_set_qos DDS_DataReaderView_set_qos

#define dython_bit_KDythonDataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define dython_bit_KDythonDataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define dython_bit_KDythonDataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define dython_bit_KDythonDataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

 DDS_ReturnCode_t
dython_bit_KDythonDataReaderView_read (
    dython_bit_KDythonDataReaderView _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataReaderView_take (
    dython_bit_KDythonDataReaderView _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataReaderView_read_next_sample (
    dython_bit_KDythonDataReaderView _this,
    dython_bit_KDython *received_data,
    DDS_SampleInfo *sample_info
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataReaderView_take_next_sample (
    dython_bit_KDythonDataReaderView _this,
    dython_bit_KDython *received_data,
    DDS_SampleInfo *sample_info
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataReaderView_read_instance (
    dython_bit_KDythonDataReaderView _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataReaderView_take_instance (
    dython_bit_KDythonDataReaderView _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataReaderView_read_next_instance (
    dython_bit_KDythonDataReaderView _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataReaderView_take_next_instance (
    dython_bit_KDythonDataReaderView _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataReaderView_return_loan (
    dython_bit_KDythonDataReaderView _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataReaderView_read_w_condition (
    dython_bit_KDythonDataReaderView _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataReaderView_take_w_condition (
    dython_bit_KDythonDataReaderView _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataReaderView_read_next_instance_w_condition (
    dython_bit_KDythonDataReaderView _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataReaderView_take_next_instance_w_condition (
    dython_bit_KDythonDataReaderView _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
dython_bit_KDythonDataReaderView_get_key_value (
    dython_bit_KDythonDataReaderView _this,
    dython_bit_KDython *key_holder,
    const DDS_InstanceHandle_t handle
    );

 DDS_InstanceHandle_t
dython_bit_KDythonDataReaderView_lookup_instance (
    dython_bit_KDythonDataReaderView _this,
    dython_bit_KDython *key_holder
    );


#define dython_bit_DythonTypeSupport DDS_TypeSupport

 dython_bit_DythonTypeSupport
dython_bit_DythonTypeSupport__alloc (
    void
    );

 DDS_ReturnCode_t
dython_bit_DythonTypeSupport_register_type (
    dython_bit_DythonTypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

 DDS_string
dython_bit_DythonTypeSupport_get_type_name (
    dython_bit_DythonTypeSupport _this
    );

#ifndef _DDS_sequence_dython_bit_Dython_defined
#define _DDS_sequence_dython_bit_Dython_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    dython_bit_Dython *_buffer;
    DDS_boolean _release;
} DDS_sequence_dython_bit_Dython;

 DDS_sequence_dython_bit_Dython *DDS_sequence_dython_bit_Dython__alloc (void);
 dython_bit_Dython *DDS_sequence_dython_bit_Dython_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_dython_bit_Dython_defined */

#define dython_bit_DythonDataWriter DDS_DataWriter

#define dython_bit_DythonDataWriter_enable DDS_Entity_enable

#define dython_bit_DythonDataWriter_get_status_changes DDS_Entity_get_status_changes

#define dython_bit_DythonDataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define dython_bit_DythonDataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define dython_bit_DythonDataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define dython_bit_DythonDataWriter_get_listener DDS_DataWriter_get_listener

#define dython_bit_DythonDataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define dython_bit_DythonDataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define dython_bit_DythonDataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define dython_bit_DythonDataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define dython_bit_DythonDataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define dython_bit_DythonDataWriter_get_publication_matched_status DDS_DataWriter_get_publication_matched_status

#define dython_bit_DythonDataWriter_get_publisher DDS_DataWriter_get_publisher

#define dython_bit_DythonDataWriter_get_qos DDS_DataWriter_get_qos

#define dython_bit_DythonDataWriter_get_topic DDS_DataWriter_get_topic

#define dython_bit_DythonDataWriter_set_listener DDS_DataWriter_set_listener

#define dython_bit_DythonDataWriter_set_qos DDS_DataWriter_set_qos

 DDS_InstanceHandle_t
dython_bit_DythonDataWriter_register_instance (
    dython_bit_DythonDataWriter _this,
    const dython_bit_Dython *instance_data
    );

 DDS_InstanceHandle_t
dython_bit_DythonDataWriter_register_instance_w_timestamp (
    dython_bit_DythonDataWriter _this,
    const dython_bit_Dython *instance_data,
    const DDS_Time_t *source_timestamp
    );

 DDS_ReturnCode_t
dython_bit_DythonDataWriter_unregister_instance (
    dython_bit_DythonDataWriter _this,
    const dython_bit_Dython *instance_data,
    const DDS_InstanceHandle_t handle
    );

 DDS_ReturnCode_t
dython_bit_DythonDataWriter_unregister_instance_w_timestamp (
    dython_bit_DythonDataWriter _this,
    const dython_bit_Dython *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

 DDS_ReturnCode_t
dython_bit_DythonDataWriter_write (
    dython_bit_DythonDataWriter _this,
    const dython_bit_Dython *instance_data,
    const DDS_InstanceHandle_t handle
    );

 DDS_ReturnCode_t
dython_bit_DythonDataWriter_write_w_timestamp (
    dython_bit_DythonDataWriter _this,
    const dython_bit_Dython *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

 DDS_ReturnCode_t
dython_bit_DythonDataWriter_dispose (
    dython_bit_DythonDataWriter _this,
    const dython_bit_Dython *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

 DDS_ReturnCode_t
dython_bit_DythonDataWriter_dispose_w_timestamp (
    dython_bit_DythonDataWriter _this,
    const dython_bit_Dython *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

 DDS_ReturnCode_t
dython_bit_DythonDataWriter_writedispose (
    dython_bit_DythonDataWriter _this,
    const dython_bit_Dython *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

 DDS_ReturnCode_t
dython_bit_DythonDataWriter_writedispose_w_timestamp (
    dython_bit_DythonDataWriter _this,
    const dython_bit_Dython *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

 DDS_ReturnCode_t
dython_bit_DythonDataWriter_get_key_value (
    dython_bit_DythonDataWriter _this,
    dython_bit_Dython *key_holder,
    const DDS_InstanceHandle_t handle
    );

 DDS_InstanceHandle_t
dython_bit_DythonDataWriter_lookup_instance (
    dython_bit_DythonDataWriter _this,
    const dython_bit_Dython *key_holder
    );

#define dython_bit_DythonDataReader DDS_DataReader

#define dython_bit_DythonDataReader_enable DDS_Entity_enable

#define dython_bit_DythonDataReader_get_status_changes DDS_Entity_get_status_changes

#define dython_bit_DythonDataReader_get_statuscondition DDS_Entity_get_statuscondition

#define dython_bit_DythonDataReader_get_instance_handle DDS_Entity_get_instance_handle

#define dython_bit_DythonDataReader_create_querycondition DDS_DataReader_create_querycondition

#define dython_bit_DythonDataReader_create_readcondition DDS_DataReader_create_readcondition

#define dython_bit_DythonDataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define dython_bit_DythonDataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define dython_bit_DythonDataReader_get_listener DDS_DataReader_get_listener

#define dython_bit_DythonDataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define dython_bit_DythonDataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define dython_bit_DythonDataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define dython_bit_DythonDataReader_get_qos DDS_DataReader_get_qos

#define dython_bit_DythonDataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define dython_bit_DythonDataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define dython_bit_DythonDataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define dython_bit_DythonDataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define dython_bit_DythonDataReader_get_subscriber DDS_DataReader_get_subscriber

#define dython_bit_DythonDataReader_get_subscription_matched_status DDS_DataReader_get_subscription_matched_status

#define dython_bit_DythonDataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define dython_bit_DythonDataReader_set_listener DDS_DataReader_set_listener

#define dython_bit_DythonDataReader_set_qos DDS_DataReader_set_qos

#define dython_bit_DythonDataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

 DDS_ReturnCode_t
dython_bit_DythonDataReader_read (
    dython_bit_DythonDataReader _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
dython_bit_DythonDataReader_take (
    dython_bit_DythonDataReader _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
dython_bit_DythonDataReader_read_w_condition (
    dython_bit_DythonDataReader _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
dython_bit_DythonDataReader_take_w_condition (
    dython_bit_DythonDataReader _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
dython_bit_DythonDataReader_read_next_sample (
    dython_bit_DythonDataReader _this,
    dython_bit_Dython *received_data,
    DDS_SampleInfo *sample_info
    );

 DDS_ReturnCode_t
dython_bit_DythonDataReader_take_next_sample (
    dython_bit_DythonDataReader _this,
    dython_bit_Dython *received_data,
    DDS_SampleInfo *sample_info
    );

 DDS_ReturnCode_t
dython_bit_DythonDataReader_read_instance (
    dython_bit_DythonDataReader _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
dython_bit_DythonDataReader_take_instance (
    dython_bit_DythonDataReader _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
dython_bit_DythonDataReader_read_next_instance (
    dython_bit_DythonDataReader _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
dython_bit_DythonDataReader_take_next_instance (
    dython_bit_DythonDataReader _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
dython_bit_DythonDataReader_read_next_instance_w_condition (
    dython_bit_DythonDataReader _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
dython_bit_DythonDataReader_take_next_instance_w_condition (
    dython_bit_DythonDataReader _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
dython_bit_DythonDataReader_return_loan (
    dython_bit_DythonDataReader _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq
    );

 DDS_ReturnCode_t
dython_bit_DythonDataReader_get_key_value (
    dython_bit_DythonDataReader _this,
    dython_bit_Dython *key_holder,
    const DDS_InstanceHandle_t handle
    );

 DDS_InstanceHandle_t
dython_bit_DythonDataReader_lookup_instance (
    dython_bit_DythonDataReader _this,
    const dython_bit_Dython *key_holder
    );

#define dython_bit_DythonDataReaderView DDS_DataReaderView

#define dython_bit_DythonDataReaderView_enable DDS_Entity_enable

#define dython_bit_DythonDataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define dython_bit_DythonDataReaderView_get_qos DDS_DataReaderView_get_qos

#define dython_bit_DythonDataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define dython_bit_DythonDataReaderView_set_qos DDS_DataReaderView_set_qos

#define dython_bit_DythonDataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define dython_bit_DythonDataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define dython_bit_DythonDataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define dython_bit_DythonDataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

 DDS_ReturnCode_t
dython_bit_DythonDataReaderView_read (
    dython_bit_DythonDataReaderView _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
dython_bit_DythonDataReaderView_take (
    dython_bit_DythonDataReaderView _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
dython_bit_DythonDataReaderView_read_next_sample (
    dython_bit_DythonDataReaderView _this,
    dython_bit_Dython *received_data,
    DDS_SampleInfo *sample_info
    );

 DDS_ReturnCode_t
dython_bit_DythonDataReaderView_take_next_sample (
    dython_bit_DythonDataReaderView _this,
    dython_bit_Dython *received_data,
    DDS_SampleInfo *sample_info
    );

 DDS_ReturnCode_t
dython_bit_DythonDataReaderView_read_instance (
    dython_bit_DythonDataReaderView _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
dython_bit_DythonDataReaderView_take_instance (
    dython_bit_DythonDataReaderView _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
dython_bit_DythonDataReaderView_read_next_instance (
    dython_bit_DythonDataReaderView _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
dython_bit_DythonDataReaderView_take_next_instance (
    dython_bit_DythonDataReaderView _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
dython_bit_DythonDataReaderView_return_loan (
    dython_bit_DythonDataReaderView _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq
    );

 DDS_ReturnCode_t
dython_bit_DythonDataReaderView_read_w_condition (
    dython_bit_DythonDataReaderView _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
dython_bit_DythonDataReaderView_take_w_condition (
    dython_bit_DythonDataReaderView _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
dython_bit_DythonDataReaderView_read_next_instance_w_condition (
    dython_bit_DythonDataReaderView _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
dython_bit_DythonDataReaderView_take_next_instance_w_condition (
    dython_bit_DythonDataReaderView _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
dython_bit_DythonDataReaderView_get_key_value (
    dython_bit_DythonDataReaderView _this,
    dython_bit_Dython *key_holder,
    const DDS_InstanceHandle_t handle
    );

 DDS_InstanceHandle_t
dython_bit_DythonDataReaderView_lookup_instance (
    dython_bit_DythonDataReaderView _this,
    dython_bit_Dython *key_holder
    );

#endif
