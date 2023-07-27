#pragma once

#include <inttypes.h>
#include <float.h>
#include <stddef.h>

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t  i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef float  f32;
typedef double f64;

typedef size_t usize;

#define U8MAX  UINT8_MAX
#define U16MAX UINT16_MAX
#define U32MAX UINT32_MAX
#define U64MAX UINT64_MAX

#define I8MAX  INT8_MAX
#define I16MAX INT8_MAX
#define I32MAX INT32_MAX
#define I64MAX INT64_MAX
#define I8MIN  INT8_MIN
#define I16MIN INT16_MIN
#define I32MIN INT32_MIN
#define I64MIN INT64_MIN

#define F32MAX FLT_MAX
#define F64MAX DBL_MAX
#define F32MIN FLT_MIN
#define F64MIN DBL_MIN

