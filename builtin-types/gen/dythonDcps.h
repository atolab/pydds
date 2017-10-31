#ifndef DYTHONDCPS_H
#define DYTHONDCPS_H

#include <dds_primitive_types.h>
#include <stdint.h>
#include <stdbool.h>


#ifndef _dython_bit_KDython_defined
#define _dython_bit_KDython_defined
#ifdef __cplusplus
struct dython_bit_KDython;
#else /* __cplusplus */
typedef struct dython_bit_KDython dython_bit_KDython;
#endif /* __cplusplus */
#endif /* _dython_bit_KDython_defined */
 dython_bit_KDython *dython_bit_KDython__alloc (void);

struct dython_bit_KDython {
    char * key;
    char * value;
};

#ifndef _dython_bit_Dython_defined
#define _dython_bit_Dython_defined
#ifdef __cplusplus
struct dython_bit_Dython;
#else /* __cplusplus */
typedef struct dython_bit_Dython dython_bit_Dython;
#endif /* __cplusplus */
#endif /* _dython_bit_Dython_defined */
 dython_bit_Dython *dython_bit_Dython__alloc (void);

struct dython_bit_Dython {
    char * value;
};

#endif
