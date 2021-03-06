#ifndef VECTOR_H
#define VECTOR_H

#include <CL/cl.h>
#include <math.h>

cl_float4 add(cl_float4 const *const restrict a,
              cl_float4 const *const restrict b);
float dot(cl_float4 const *const restrict a, cl_float4 const *const restrict b);
cl_float4 intersection_position(cl_float4 const *const restrict a,
                                cl_float4 const *const restrict b,
                                float const length);
cl_float4 normalize(cl_float4 const *const restrict vector);
cl_float4 sub(cl_float4 const *const restrict a,
              cl_float4 const *const restrict b);

#endif
