#if defined (__cplusplus)
extern "C" {
#endif

#include <dds_dcps.h>
#include <dds_dcps_private.h>

#include "dythonSacDcps.h"
#include "dythonSplDcps.h"

DDS_sequence_dython_bit_KDython *DDS_sequence_dython_bit_KDython__alloc (void)
{
    return (DDS_sequence_dython_bit_KDython *)DDS_alloc(sizeof(DDS_sequence_dython_bit_KDython), (DDS_deallocatorType)DDS_sequence_free);
}

dython_bit_KDython *DDS_sequence_dython_bit_KDython_allocbuf (DDS_unsigned_long len)
{
    DDS_ReturnCode_t DDS_sequence_dython_bit_KDython_freebuf (void *buffer);

    return (dython_bit_KDython *)DDS_sequence_allocbuf (DDS_sequence_dython_bit_KDython_freebuf, sizeof (dython_bit_KDython), len);
}

DDS_ReturnCode_t DDS_sequence_dython_bit_KDython_freebuf (void *buffer);
DDS_ReturnCode_t DDS_sequence_dython_bit_KDython_freebuf (void *buffer)
{
    DDS_unsigned_long *count = (DDS_unsigned_long *)DDS__header (buffer);
    dython_bit_KDython *b = (dython_bit_KDython *)buffer;
    DDS_unsigned_long i;
    DDS_ReturnCode_t dython_bit_KDython__free (void *object);

    for (i = 0; i < *count; i++) {
        (void) dython_bit_KDython__free (&b[i]);
    }
    return DDS_RETCODE_OK;
}

extern v_copyin_result __dython_bit_KDython__copyIn(c_base base, const void *from, void *to);
extern void __dython_bit_KDython__copyOut(const void *from, void *to);


dython_bit_KDythonTypeSupport
dython_bit_KDythonTypeSupport__alloc (
    void
    )
{
    dython_bit_KDythonTypeSupport result;
    result = DDS_TypeSupportNew (
            "dython::bit::KDython",
            "",
            "key",
            dython_bit_KDython_metaDescriptor,
            dython_bit_KDython_metaDescriptorArrLength,
            dython_bit_KDython_metaDescriptorLength,
            (DDS_copyIn)__dython_bit_KDython__copyIn,
            (DDS_copyOut)__dython_bit_KDython__copyOut,
            (DDS_unsigned_long)(sizeof(dython_bit_KDython)),
            (DDS_allocBuffer)DDS_sequence_dython_bit_KDython_allocbuf
        );
    return result;
}

DDS_ReturnCode_t
dython_bit_KDythonTypeSupport_register_type (
    dython_bit_KDythonTypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_TypeSupport_register_type (
	    (DDS_TypeSupport)_this,
	    domain,
	    name
	);
    return result;
}

DDS_string
dython_bit_KDythonTypeSupport_get_type_name (
    dython_bit_KDythonTypeSupport _this
    )
{
    DDS_string result = (DDS_string)
        DDS_TypeSupport_get_type_name (
	    (DDS_TypeSupport)_this
	);
    return result;
}

DDS_InstanceHandle_t
dython_bit_KDythonDataWriter_register_instance (
    dython_bit_KDythonDataWriter _this,
    const dython_bit_KDython *instance_data
    )
{
    DDS_InstanceHandle_t result = (DDS_InstanceHandle_t)
        DDS_DataWriter_register_instance (
	    (DDS_DataWriter)_this,
	    (const DDS_Sample)instance_data
	);
    return result;
}

DDS_InstanceHandle_t
dython_bit_KDythonDataWriter_register_instance_w_timestamp (
    dython_bit_KDythonDataWriter _this,
    const dython_bit_KDython *instance_data,
    const DDS_Time_t *source_timestamp
    )
{
    DDS_InstanceHandle_t result = (DDS_InstanceHandle_t)
        DDS_DataWriter_register_instance_w_timestamp (
	    (DDS_DataWriter)_this,
	    (const DDS_Sample)instance_data,
	    source_timestamp
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_KDythonDataWriter_unregister_instance (
    dython_bit_KDythonDataWriter _this,
    const dython_bit_KDython *instance_data,
    const DDS_InstanceHandle_t handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataWriter_unregister_instance (
	    (const DDS_DataWriter)_this,
	    (DDS_Sample)instance_data,
	    handle
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_KDythonDataWriter_unregister_instance_w_timestamp (
    dython_bit_KDythonDataWriter _this,
    const dython_bit_KDython *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataWriter_unregister_instance_w_timestamp (
	    (DDS_DataWriter)_this,
	    (const DDS_Sample)instance_data,
	    handle,
	    source_timestamp
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_KDythonDataWriter_write (
    dython_bit_KDythonDataWriter _this,
    const dython_bit_KDython *instance_data,
    const DDS_InstanceHandle_t handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataWriter_write (
	    (DDS_DataWriter)_this,
	    (const DDS_Sample)instance_data,
	    handle
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_KDythonDataWriter_write_w_timestamp (
    dython_bit_KDythonDataWriter _this,
    const dython_bit_KDython *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataWriter_write_w_timestamp (
	    (DDS_DataWriter)_this,
	    (const DDS_Sample)instance_data,
	    handle,
	    source_timestamp
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_KDythonDataWriter_dispose (
    dython_bit_KDythonDataWriter _this,
    const dython_bit_KDython *instance_data,
    const DDS_InstanceHandle_t instance_handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataWriter_dispose (
	    (DDS_DataWriter)_this,
	    (const DDS_Sample)instance_data,
	    instance_handle
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_KDythonDataWriter_dispose_w_timestamp (
    dython_bit_KDythonDataWriter _this,
    const dython_bit_KDython *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataWriter_dispose_w_timestamp (
	    (DDS_DataWriter)_this,
	    (const DDS_Sample)instance_data,
	    instance_handle,
	    source_timestamp
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_KDythonDataWriter_writedispose (
    dython_bit_KDythonDataWriter _this,
    const dython_bit_KDython *instance_data,
    const DDS_InstanceHandle_t instance_handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataWriter_writedispose (
	    (DDS_DataWriter)_this,
	    (const DDS_Sample)instance_data,
	    instance_handle
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_KDythonDataWriter_writedispose_w_timestamp (
    dython_bit_KDythonDataWriter _this,
    const dython_bit_KDython *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataWriter_writedispose_w_timestamp (
	    (DDS_DataWriter)_this,
	    (const DDS_Sample)instance_data,
	    instance_handle,
	    source_timestamp
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_KDythonDataWriter_get_key_value (
    dython_bit_KDythonDataWriter _this,
    dython_bit_KDython *key_holder,
    const DDS_InstanceHandle_t handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataWriter_get_key_value (
	    (DDS_DataWriter)_this,
	    (DDS_Sample)key_holder,
	    handle
	);
    return result;
}

DDS_InstanceHandle_t
dython_bit_KDythonDataWriter_lookup_instance (
    dython_bit_KDythonDataWriter _this,
    const dython_bit_KDython *key_holder
    )
{
    DDS_InstanceHandle_t result = (DDS_InstanceHandle_t)
        DDS_DataWriter_lookup_instance (
        (DDS_DataWriter)_this,
        (DDS_Sample)key_holder
    );
    return result;
}

DDS_ReturnCode_t
dython_bit_KDythonDataReader_read (
    dython_bit_KDythonDataReader _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReader_read (
	    (DDS_DataReader)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_KDythonDataReader_take (
    dython_bit_KDythonDataReader _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReader_take (
	    (DDS_DataReader)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_KDythonDataReader_read_w_condition (
    dython_bit_KDythonDataReader _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReader_read_w_condition (
	    (DDS_DataReader)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_condition
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_KDythonDataReader_take_w_condition (
    dython_bit_KDythonDataReader _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReader_take_w_condition (
	    (DDS_DataReader)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_condition
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_KDythonDataReader_read_next_sample (
    dython_bit_KDythonDataReader _this,
    dython_bit_KDython *received_data,
    DDS_SampleInfo *sample_info
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReader_read_next_sample (
	    (DDS_DataReader)_this,
	    (DDS_Sample)received_data,
	    sample_info
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_KDythonDataReader_take_next_sample (
    dython_bit_KDythonDataReader _this,
    dython_bit_KDython *received_data,
    DDS_SampleInfo *sample_info
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReader_take_next_sample (
	    (DDS_DataReader)_this,
	    (DDS_Sample)received_data,
	    sample_info
	);
    return result;
}

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
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReader_read_instance (
	    (DDS_DataReader)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

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
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReader_take_instance (
	    (DDS_DataReader)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

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
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReader_read_next_instance (
	    (DDS_DataReader)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

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
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReader_take_next_instance (
	    (DDS_DataReader)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_KDythonDataReader_read_next_instance_w_condition (
    dython_bit_KDythonDataReader _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReader_read_next_instance_w_condition (
	    (DDS_DataReader)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    a_condition
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_KDythonDataReader_take_next_instance_w_condition (
    dython_bit_KDythonDataReader _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReader_take_next_instance_w_condition (
	    (DDS_DataReader)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    a_condition
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_KDythonDataReader_return_loan (
    dython_bit_KDythonDataReader _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReader_return_loan (
            (DDS_DataReader)_this,
            (_DDS_sequence)received_data,
            info_seq
    );
    return result;
}

DDS_ReturnCode_t
dython_bit_KDythonDataReader_get_key_value (
    dython_bit_KDythonDataReader _this,
    dython_bit_KDython *key_holder,
    const DDS_InstanceHandle_t handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReader_get_key_value (
	    (DDS_DataReader)_this,
	    (DDS_Sample)key_holder,
	    handle
	);
    return result;
}

DDS_InstanceHandle_t
dython_bit_KDythonDataReader_lookup_instance (
    dython_bit_KDythonDataReader _this,
    const dython_bit_KDython *key_holder
    )
{
    DDS_InstanceHandle_t result = (DDS_InstanceHandle_t)
        DDS_DataReader_lookup_instance (
	    (DDS_DataReader)_this,
	    (DDS_Sample)key_holder
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_KDythonDataReaderView_read (
    dython_bit_KDythonDataReaderView _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReaderView_read (
	    (DDS_DataReaderView)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_KDythonDataReaderView_take (
    dython_bit_KDythonDataReaderView _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReaderView_take (
	    (DDS_DataReaderView)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_KDythonDataReaderView_read_next_sample (
    dython_bit_KDythonDataReaderView _this,
    dython_bit_KDython *received_data,
    DDS_SampleInfo *sample_info
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReaderView_read_next_sample (
	    (DDS_DataReaderView)_this,
	    (DDS_Sample)received_data,
	    sample_info
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_KDythonDataReaderView_take_next_sample (
    dython_bit_KDythonDataReaderView _this,
    dython_bit_KDython *received_data,
    DDS_SampleInfo *sample_info
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReaderView_take_next_sample (
	    (DDS_DataReaderView)_this,
	    (DDS_Sample)received_data,
	    sample_info
	);
    return result;
}

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
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReaderView_read_instance (
	    (DDS_DataReaderView)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

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
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReaderView_take_instance (
	    (DDS_DataReaderView)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

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
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReaderView_read_next_instance (
	    (DDS_DataReaderView)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

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
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReaderView_take_next_instance (
	    (DDS_DataReaderView)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_KDythonDataReaderView_return_loan (
    dython_bit_KDythonDataReaderView _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReaderView_return_loan (
            (DDS_DataReaderView)_this,
            (_DDS_sequence)received_data,
            info_seq
    );

    if ( result == DDS_RETCODE_OK ) {
        DDS_free(received_data->_buffer);
        received_data->_length  = 0;
        received_data->_maximum = 0;
        received_data->_buffer  = NULL;
        
        DDS_free(info_seq->_buffer);
        info_seq->_length  = 0;
        info_seq->_maximum = 0;
        info_seq->_buffer  = NULL;
    }

    return result;
}


DDS_ReturnCode_t
dython_bit_KDythonDataReaderView_read_w_condition (
    dython_bit_KDythonDataReaderView _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReaderView_read_w_condition (
	    (DDS_DataReaderView)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
            a_condition
	);
    return result;
}


DDS_ReturnCode_t
dython_bit_KDythonDataReaderView_take_w_condition (
    dython_bit_KDythonDataReaderView _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReaderView_take_w_condition (
	    (DDS_DataReaderView)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
            a_condition
	);
    return result;
}


DDS_ReturnCode_t
dython_bit_KDythonDataReaderView_read_next_instance_w_condition (
    dython_bit_KDythonDataReaderView _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
   )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReaderView_read_next_instance_w_condition (
	    (DDS_DataReaderView)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
            a_condition
	);
    return result;
}


DDS_ReturnCode_t
dython_bit_KDythonDataReaderView_take_next_instance_w_condition (
    dython_bit_KDythonDataReaderView _this,
    DDS_sequence_dython_bit_KDython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
   )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReaderView_take_next_instance_w_condition (
	    (DDS_DataReaderView)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
            a_condition
	);
    return result;
}


DDS_ReturnCode_t
dython_bit_KDythonDataReaderView_get_key_value (
    dython_bit_KDythonDataReaderView _this,
    dython_bit_KDython *key_holder,
    const DDS_InstanceHandle_t handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReaderView_get_key_value (
	    (DDS_DataReaderView)_this,
	    (DDS_Sample)key_holder,
	    handle
	);
    return result;
}


DDS_InstanceHandle_t
dython_bit_KDythonDataReaderView_lookup_instance (
    dython_bit_KDythonDataReaderView _this,
    dython_bit_KDython *key_holder
    )
{
    DDS_InstanceHandle_t result = (DDS_InstanceHandle_t)
        DDS_DataReaderView_lookup_instance (
	    (DDS_DataReaderView)_this,
	    (DDS_Sample)key_holder
	);
    return result;
}

DDS_sequence_dython_bit_Dython *DDS_sequence_dython_bit_Dython__alloc (void)
{
    return (DDS_sequence_dython_bit_Dython *)DDS_alloc(sizeof(DDS_sequence_dython_bit_Dython), (DDS_deallocatorType)DDS_sequence_free);
}

dython_bit_Dython *DDS_sequence_dython_bit_Dython_allocbuf (DDS_unsigned_long len)
{
    DDS_ReturnCode_t DDS_sequence_dython_bit_Dython_freebuf (void *buffer);

    return (dython_bit_Dython *)DDS_sequence_allocbuf (DDS_sequence_dython_bit_Dython_freebuf, sizeof (dython_bit_Dython), len);
}

DDS_ReturnCode_t DDS_sequence_dython_bit_Dython_freebuf (void *buffer);
DDS_ReturnCode_t DDS_sequence_dython_bit_Dython_freebuf (void *buffer)
{
    DDS_unsigned_long *count = (DDS_unsigned_long *)DDS__header (buffer);
    dython_bit_Dython *b = (dython_bit_Dython *)buffer;
    DDS_unsigned_long i;
    DDS_ReturnCode_t dython_bit_Dython__free (void *object);

    for (i = 0; i < *count; i++) {
        (void) dython_bit_Dython__free (&b[i]);
    }
    return DDS_RETCODE_OK;
}

extern v_copyin_result __dython_bit_Dython__copyIn(c_base base, const void *from, void *to);
extern void __dython_bit_Dython__copyOut(const void *from, void *to);


dython_bit_DythonTypeSupport
dython_bit_DythonTypeSupport__alloc (
    void
    )
{
    dython_bit_DythonTypeSupport result;
    result = DDS_TypeSupportNew (
            "dython::bit::Dython",
            "",
            "",
            dython_bit_Dython_metaDescriptor,
            dython_bit_Dython_metaDescriptorArrLength,
            dython_bit_Dython_metaDescriptorLength,
            (DDS_copyIn)__dython_bit_Dython__copyIn,
            (DDS_copyOut)__dython_bit_Dython__copyOut,
            (DDS_unsigned_long)(sizeof(dython_bit_Dython)),
            (DDS_allocBuffer)DDS_sequence_dython_bit_Dython_allocbuf
        );
    return result;
}

DDS_ReturnCode_t
dython_bit_DythonTypeSupport_register_type (
    dython_bit_DythonTypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_TypeSupport_register_type (
	    (DDS_TypeSupport)_this,
	    domain,
	    name
	);
    return result;
}

DDS_string
dython_bit_DythonTypeSupport_get_type_name (
    dython_bit_DythonTypeSupport _this
    )
{
    DDS_string result = (DDS_string)
        DDS_TypeSupport_get_type_name (
	    (DDS_TypeSupport)_this
	);
    return result;
}

DDS_InstanceHandle_t
dython_bit_DythonDataWriter_register_instance (
    dython_bit_DythonDataWriter _this,
    const dython_bit_Dython *instance_data
    )
{
    DDS_InstanceHandle_t result = (DDS_InstanceHandle_t)
        DDS_DataWriter_register_instance (
	    (DDS_DataWriter)_this,
	    (const DDS_Sample)instance_data
	);
    return result;
}

DDS_InstanceHandle_t
dython_bit_DythonDataWriter_register_instance_w_timestamp (
    dython_bit_DythonDataWriter _this,
    const dython_bit_Dython *instance_data,
    const DDS_Time_t *source_timestamp
    )
{
    DDS_InstanceHandle_t result = (DDS_InstanceHandle_t)
        DDS_DataWriter_register_instance_w_timestamp (
	    (DDS_DataWriter)_this,
	    (const DDS_Sample)instance_data,
	    source_timestamp
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_DythonDataWriter_unregister_instance (
    dython_bit_DythonDataWriter _this,
    const dython_bit_Dython *instance_data,
    const DDS_InstanceHandle_t handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataWriter_unregister_instance (
	    (const DDS_DataWriter)_this,
	    (DDS_Sample)instance_data,
	    handle
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_DythonDataWriter_unregister_instance_w_timestamp (
    dython_bit_DythonDataWriter _this,
    const dython_bit_Dython *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataWriter_unregister_instance_w_timestamp (
	    (DDS_DataWriter)_this,
	    (const DDS_Sample)instance_data,
	    handle,
	    source_timestamp
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_DythonDataWriter_write (
    dython_bit_DythonDataWriter _this,
    const dython_bit_Dython *instance_data,
    const DDS_InstanceHandle_t handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataWriter_write (
	    (DDS_DataWriter)_this,
	    (const DDS_Sample)instance_data,
	    handle
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_DythonDataWriter_write_w_timestamp (
    dython_bit_DythonDataWriter _this,
    const dython_bit_Dython *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataWriter_write_w_timestamp (
	    (DDS_DataWriter)_this,
	    (const DDS_Sample)instance_data,
	    handle,
	    source_timestamp
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_DythonDataWriter_dispose (
    dython_bit_DythonDataWriter _this,
    const dython_bit_Dython *instance_data,
    const DDS_InstanceHandle_t instance_handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataWriter_dispose (
	    (DDS_DataWriter)_this,
	    (const DDS_Sample)instance_data,
	    instance_handle
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_DythonDataWriter_dispose_w_timestamp (
    dython_bit_DythonDataWriter _this,
    const dython_bit_Dython *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataWriter_dispose_w_timestamp (
	    (DDS_DataWriter)_this,
	    (const DDS_Sample)instance_data,
	    instance_handle,
	    source_timestamp
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_DythonDataWriter_writedispose (
    dython_bit_DythonDataWriter _this,
    const dython_bit_Dython *instance_data,
    const DDS_InstanceHandle_t instance_handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataWriter_writedispose (
	    (DDS_DataWriter)_this,
	    (const DDS_Sample)instance_data,
	    instance_handle
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_DythonDataWriter_writedispose_w_timestamp (
    dython_bit_DythonDataWriter _this,
    const dython_bit_Dython *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataWriter_writedispose_w_timestamp (
	    (DDS_DataWriter)_this,
	    (const DDS_Sample)instance_data,
	    instance_handle,
	    source_timestamp
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_DythonDataWriter_get_key_value (
    dython_bit_DythonDataWriter _this,
    dython_bit_Dython *key_holder,
    const DDS_InstanceHandle_t handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataWriter_get_key_value (
	    (DDS_DataWriter)_this,
	    (DDS_Sample)key_holder,
	    handle
	);
    return result;
}

DDS_InstanceHandle_t
dython_bit_DythonDataWriter_lookup_instance (
    dython_bit_DythonDataWriter _this,
    const dython_bit_Dython *key_holder
    )
{
    DDS_InstanceHandle_t result = (DDS_InstanceHandle_t)
        DDS_DataWriter_lookup_instance (
        (DDS_DataWriter)_this,
        (DDS_Sample)key_holder
    );
    return result;
}

DDS_ReturnCode_t
dython_bit_DythonDataReader_read (
    dython_bit_DythonDataReader _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReader_read (
	    (DDS_DataReader)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_DythonDataReader_take (
    dython_bit_DythonDataReader _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReader_take (
	    (DDS_DataReader)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_DythonDataReader_read_w_condition (
    dython_bit_DythonDataReader _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReader_read_w_condition (
	    (DDS_DataReader)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_condition
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_DythonDataReader_take_w_condition (
    dython_bit_DythonDataReader _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReader_take_w_condition (
	    (DDS_DataReader)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_condition
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_DythonDataReader_read_next_sample (
    dython_bit_DythonDataReader _this,
    dython_bit_Dython *received_data,
    DDS_SampleInfo *sample_info
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReader_read_next_sample (
	    (DDS_DataReader)_this,
	    (DDS_Sample)received_data,
	    sample_info
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_DythonDataReader_take_next_sample (
    dython_bit_DythonDataReader _this,
    dython_bit_Dython *received_data,
    DDS_SampleInfo *sample_info
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReader_take_next_sample (
	    (DDS_DataReader)_this,
	    (DDS_Sample)received_data,
	    sample_info
	);
    return result;
}

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
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReader_read_instance (
	    (DDS_DataReader)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

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
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReader_take_instance (
	    (DDS_DataReader)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

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
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReader_read_next_instance (
	    (DDS_DataReader)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

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
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReader_take_next_instance (
	    (DDS_DataReader)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_DythonDataReader_read_next_instance_w_condition (
    dython_bit_DythonDataReader _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReader_read_next_instance_w_condition (
	    (DDS_DataReader)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    a_condition
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_DythonDataReader_take_next_instance_w_condition (
    dython_bit_DythonDataReader _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReader_take_next_instance_w_condition (
	    (DDS_DataReader)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    a_condition
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_DythonDataReader_return_loan (
    dython_bit_DythonDataReader _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReader_return_loan (
            (DDS_DataReader)_this,
            (_DDS_sequence)received_data,
            info_seq
    );
    return result;
}

DDS_ReturnCode_t
dython_bit_DythonDataReader_get_key_value (
    dython_bit_DythonDataReader _this,
    dython_bit_Dython *key_holder,
    const DDS_InstanceHandle_t handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReader_get_key_value (
	    (DDS_DataReader)_this,
	    (DDS_Sample)key_holder,
	    handle
	);
    return result;
}

DDS_InstanceHandle_t
dython_bit_DythonDataReader_lookup_instance (
    dython_bit_DythonDataReader _this,
    const dython_bit_Dython *key_holder
    )
{
    DDS_InstanceHandle_t result = (DDS_InstanceHandle_t)
        DDS_DataReader_lookup_instance (
	    (DDS_DataReader)_this,
	    (DDS_Sample)key_holder
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_DythonDataReaderView_read (
    dython_bit_DythonDataReaderView _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReaderView_read (
	    (DDS_DataReaderView)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_DythonDataReaderView_take (
    dython_bit_DythonDataReaderView _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReaderView_take (
	    (DDS_DataReaderView)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_DythonDataReaderView_read_next_sample (
    dython_bit_DythonDataReaderView _this,
    dython_bit_Dython *received_data,
    DDS_SampleInfo *sample_info
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReaderView_read_next_sample (
	    (DDS_DataReaderView)_this,
	    (DDS_Sample)received_data,
	    sample_info
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_DythonDataReaderView_take_next_sample (
    dython_bit_DythonDataReaderView _this,
    dython_bit_Dython *received_data,
    DDS_SampleInfo *sample_info
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReaderView_take_next_sample (
	    (DDS_DataReaderView)_this,
	    (DDS_Sample)received_data,
	    sample_info
	);
    return result;
}

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
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReaderView_read_instance (
	    (DDS_DataReaderView)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

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
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReaderView_take_instance (
	    (DDS_DataReaderView)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

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
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReaderView_read_next_instance (
	    (DDS_DataReaderView)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

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
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReaderView_take_next_instance (
	    (DDS_DataReaderView)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
dython_bit_DythonDataReaderView_return_loan (
    dython_bit_DythonDataReaderView _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReaderView_return_loan (
            (DDS_DataReaderView)_this,
            (_DDS_sequence)received_data,
            info_seq
    );

    if ( result == DDS_RETCODE_OK ) {
        DDS_free(received_data->_buffer);
        received_data->_length  = 0;
        received_data->_maximum = 0;
        received_data->_buffer  = NULL;
        
        DDS_free(info_seq->_buffer);
        info_seq->_length  = 0;
        info_seq->_maximum = 0;
        info_seq->_buffer  = NULL;
    }

    return result;
}


DDS_ReturnCode_t
dython_bit_DythonDataReaderView_read_w_condition (
    dython_bit_DythonDataReaderView _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReaderView_read_w_condition (
	    (DDS_DataReaderView)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
            a_condition
	);
    return result;
}


DDS_ReturnCode_t
dython_bit_DythonDataReaderView_take_w_condition (
    dython_bit_DythonDataReaderView _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReaderView_take_w_condition (
	    (DDS_DataReaderView)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
            a_condition
	);
    return result;
}


DDS_ReturnCode_t
dython_bit_DythonDataReaderView_read_next_instance_w_condition (
    dython_bit_DythonDataReaderView _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
   )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReaderView_read_next_instance_w_condition (
	    (DDS_DataReaderView)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
            a_condition
	);
    return result;
}


DDS_ReturnCode_t
dython_bit_DythonDataReaderView_take_next_instance_w_condition (
    dython_bit_DythonDataReaderView _this,
    DDS_sequence_dython_bit_Dython *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
   )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReaderView_take_next_instance_w_condition (
	    (DDS_DataReaderView)_this,
	    (_DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
            a_condition
	);
    return result;
}


DDS_ReturnCode_t
dython_bit_DythonDataReaderView_get_key_value (
    dython_bit_DythonDataReaderView _this,
    dython_bit_Dython *key_holder,
    const DDS_InstanceHandle_t handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS_DataReaderView_get_key_value (
	    (DDS_DataReaderView)_this,
	    (DDS_Sample)key_holder,
	    handle
	);
    return result;
}


DDS_InstanceHandle_t
dython_bit_DythonDataReaderView_lookup_instance (
    dython_bit_DythonDataReaderView _this,
    dython_bit_Dython *key_holder
    )
{
    DDS_InstanceHandle_t result = (DDS_InstanceHandle_t)
        DDS_DataReaderView_lookup_instance (
	    (DDS_DataReaderView)_this,
	    (DDS_Sample)key_holder
	);
    return result;
}

#if defined (__cplusplus)
}
#endif
