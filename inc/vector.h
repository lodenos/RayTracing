#ifndef VECTOR_H
#define VECTOR_H

#include <CL/cl.h>
#include <math.h>

cl_float4 add(cl_float4 *a, cl_float4 *b);
float dot(cl_float4 *a, cl_float4 *b);
cl_float4 normalize(cl_float4 *vector);
cl_float4 sub(cl_float4 *a, cl_float4 *b);

#endif
