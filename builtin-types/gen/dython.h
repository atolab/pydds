#ifndef VORTEX_C99_DYTHON_H_
#define VORTEX_C99_DYTHON_H_

#include "dds.h"
#include "dythonDcps.h" /* add to C file instead? */



#ifdef __cplusplus
extern "C" {
#endif

 extern const dds_topic_descriptor_t dython_bit_KDython_desc;


#define dython_bit_KDython_free(d,o) dds_sample_free ((d), &dython_bit_KDython_desc, (o))


 extern const dds_topic_descriptor_t dython_bit_Dython_desc;


#define dython_bit_Dython_free(d,o) dds_sample_free ((d), &dython_bit_Dython_desc, (o))


#ifdef __cplusplus
}
#endif

#endif /* VORTEX_C99_DYTHON_H_ */
