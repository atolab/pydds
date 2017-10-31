#include "dds_dcps.h"
#include "dython.h"
#include "dythonSacDcps.h"
#include "dds.h"

DDS_ReturnCode_t
dython_bit_KDython_type_registration(
    dds_entity_t pp,
    void *arg);
DDS_ReturnCode_t
dython_bit_KDython_type_registration(
    dds_entity_t pp,
    void *arg)
{
    DDS_ReturnCode_t result = DDS_RETCODE_OUT_OF_RESOURCES;
    dython_bit_KDythonTypeSupport ts;

    (void)arg;

    ts = dython_bit_KDythonTypeSupport__alloc();
    if (ts) {
        result = dython_bit_KDythonTypeSupport_register_type(ts, pp, "dython::bit::KDython");
        DDS_free(ts);
    }

    return result;
}

int dython_bit_KDython__free(void*);

const dds_topic_descriptor_t dython_bit_KDython_desc = {
    dython_bit_KDython_type_registration,
    "dython::bit::KDython",
    sizeof(dython_bit_KDython),
    dython_bit_KDython__free,
    NULL
};

DDS_ReturnCode_t
dython_bit_Dython_type_registration(
    dds_entity_t pp,
    void *arg);
DDS_ReturnCode_t
dython_bit_Dython_type_registration(
    dds_entity_t pp,
    void *arg)
{
    DDS_ReturnCode_t result = DDS_RETCODE_OUT_OF_RESOURCES;
    dython_bit_DythonTypeSupport ts;

    (void)arg;

    ts = dython_bit_DythonTypeSupport__alloc();
    if (ts) {
        result = dython_bit_DythonTypeSupport_register_type(ts, pp, "dython::bit::Dython");
        DDS_free(ts);
    }

    return result;
}

int dython_bit_Dython__free(void*);

const dds_topic_descriptor_t dython_bit_Dython_desc = {
    dython_bit_Dython_type_registration,
    "dython::bit::Dython",
    sizeof(dython_bit_Dython),
    dython_bit_Dython__free,
    NULL
};

