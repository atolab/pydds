#if defined (__cplusplus)
extern "C" {
#endif

#include "vortex_os.h"
#include "dythonSplDcps.h"
#include "dythonDcps.h"

/* Code generated in file: /Users/gabri/Workspace/opensplice/ospli/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 149 */
/* Code generated in file: /Users/gabri/Workspace/opensplice/ospli/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 155 */
#include <v_copyIn.h>
#include <v_topic.h>
#include <string.h>
#include <os_report.h>

/* Code generated in file: /Users/gabri/Workspace/opensplice/ospli/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 236 */
v_copyin_result
__dython_bit_KDython__copyIn(c_base base, const void *_from, void *_to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;

    const dython_bit_KDython *from = (const dython_bit_KDython *)_from;
    struct _dython_bit_KDython *to = (struct _dython_bit_KDython *)_to;
/* Code generated in file: /Users/gabri/Workspace/opensplice/ospli/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 543 */
/* Code generated in file: /Users/gabri/Workspace/opensplice/ospli/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 325 */
#ifdef OSPL_BOUNDS_CHECK
    if (from->key) {
/* Code generated in file: /Users/gabri/Workspace/opensplice/ospli/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 356 */
        to->key = c_stringNew_s(base, from->key);
        if (to->key == NULL) {
            result = V_COPYIN_RESULT_OUT_OF_MEMORY;
        }
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'dython::bit::KDython.key' of type 'c_string' is NULL.");
        result = V_COPYIN_RESULT_INVALID;
    }
#else
    to->key = c_stringNew_s(base, from->key);
    if ((to->key != NULL) && (to->key == NULL)) {
        result = V_COPYIN_RESULT_OUT_OF_MEMORY;
    }
#endif
/* Code generated in file: /Users/gabri/Workspace/opensplice/ospli/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 543 */
/* Code generated in file: /Users/gabri/Workspace/opensplice/ospli/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 325 */
#ifdef OSPL_BOUNDS_CHECK
    if (from->value) {
/* Code generated in file: /Users/gabri/Workspace/opensplice/ospli/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 356 */
        to->value = c_stringNew_s(base, from->value);
        if (to->value == NULL) {
            result = V_COPYIN_RESULT_OUT_OF_MEMORY;
        }
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'dython::bit::KDython.value' of type 'c_string' is NULL.");
        result = V_COPYIN_RESULT_INVALID;
    }
#else
    to->value = c_stringNew_s(base, from->value);
    if ((to->value != NULL) && (to->value == NULL)) {
        result = V_COPYIN_RESULT_OUT_OF_MEMORY;
    }
#endif
/* Code generated in file: /Users/gabri/Workspace/opensplice/ospli/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 271 */
    (void) base;
    return result;
}

/* Code generated in file: /Users/gabri/Workspace/opensplice/ospli/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 236 */
v_copyin_result
__dython_bit_Dython__copyIn(c_base base, const void *_from, void *_to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;

    const dython_bit_Dython *from = (const dython_bit_Dython *)_from;
    struct _dython_bit_Dython *to = (struct _dython_bit_Dython *)_to;
/* Code generated in file: /Users/gabri/Workspace/opensplice/ospli/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 543 */
/* Code generated in file: /Users/gabri/Workspace/opensplice/ospli/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 325 */
#ifdef OSPL_BOUNDS_CHECK
    if (from->value) {
/* Code generated in file: /Users/gabri/Workspace/opensplice/ospli/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 356 */
        to->value = c_stringNew_s(base, from->value);
        if (to->value == NULL) {
            result = V_COPYIN_RESULT_OUT_OF_MEMORY;
        }
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'dython::bit::Dython.value' of type 'c_string' is NULL.");
        result = V_COPYIN_RESULT_INVALID;
    }
#else
    to->value = c_stringNew_s(base, from->value);
    if ((to->value != NULL) && (to->value == NULL)) {
        result = V_COPYIN_RESULT_OUT_OF_MEMORY;
    }
#endif
/* Code generated in file: /Users/gabri/Workspace/opensplice/ospli/src/tools/idlpp/code/idl_genCorbaCCopyin.c at line: 271 */
    (void) base;
    return result;
}

#include <dds_dcps_private.h>

void
__dython_bit_KDython__copyOut(const void *_from, void *_to)
{
    const struct _dython_bit_KDython *from = (const struct _dython_bit_KDython *)_from;
    dython_bit_KDython *to = (dython_bit_KDython *)_to;
    DDS_string_replace (from->key ? from->key : "", &to->key);
    DDS_string_replace (from->value ? from->value : "", &to->value);
}

void
__dython_bit_Dython__copyOut(const void *_from, void *_to)
{
    const struct _dython_bit_Dython *from = (const struct _dython_bit_Dython *)_from;
    dython_bit_Dython *to = (dython_bit_Dython *)_to;
    DDS_string_replace (from->value ? from->value : "", &to->value);
}

dython_bit_KDython *dython_bit_KDython__alloc (void)
{
    DDS_ReturnCode_t dython_bit_KDython__free (void *object);

    return (dython_bit_KDython *)DDS_alloc(sizeof(dython_bit_KDython), dython_bit_KDython__free);
}

DDS_ReturnCode_t dython_bit_KDython__free (void *object);
DDS_ReturnCode_t dython_bit_KDython__free (void *object)
{
    dython_bit_KDython *o = (dython_bit_KDython *)object;

    (void) o;

    DDS_string_clean (&o->key);
    DDS_string_clean (&o->value);
    return DDS_RETCODE_OK;
}

dython_bit_Dython *dython_bit_Dython__alloc (void)
{
    DDS_ReturnCode_t dython_bit_Dython__free (void *object);

    return (dython_bit_Dython *)DDS_alloc(sizeof(dython_bit_Dython), dython_bit_Dython__free);
}

DDS_ReturnCode_t dython_bit_Dython__free (void *object);
DDS_ReturnCode_t dython_bit_Dython__free (void *object)
{
    dython_bit_Dython *o = (dython_bit_Dython *)object;

    (void) o;

    DDS_string_clean (&o->value);
    return DDS_RETCODE_OK;
}

const char * dython_bit_KDython_metaDescriptor[] = {"<MetaData version=\"1.0.0\"><Module name=\"dython\"><Module name=\"bit\"><Struct name=\"KDython\"><Member name=\"key\">",
"<String/></Member><Member name=\"value\"><String/></Member></Struct></Module></Module></MetaData>"};
const int  dython_bit_KDython_metaDescriptorArrLength = 2;
const int  dython_bit_KDython_metaDescriptorLength = 216;
const char * dython_bit_Dython_metaDescriptor[] = {"<MetaData version=\"1.0.0\"><Module name=\"dython\"><Module name=\"bit\"><Struct name=\"Dython\"><Member name=\"value\">",
"<String/></Member></Struct></Module></Module></MetaData>"};
const int  dython_bit_Dython_metaDescriptorArrLength = 2;
const int  dython_bit_Dython_metaDescriptorLength = 176;
#if defined (__cplusplus)
}
#endif
