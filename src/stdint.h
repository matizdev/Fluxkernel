#ifndef _STDINT_H
#define _STDINT_H

// Integer types with specific widths
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef int int32_t;
typedef unsigned int uint32_t;
typedef long long int64_t;
typedef unsigned long long uint64_t;

// Minimum and maximum values for each type
#define INT8_MIN (-128)
#define INT8_MAX 127
#define UINT8_MAX 255

#define INT16_MIN (-32768)
#define INT16_MAX 32767
#define UINT16_MAX 65535

#define INT32_MIN (-2147483648)
#define INT32_MAX 2147483647
#define UINT32_MAX 4294967295

#define INT64_MIN (-9223372036854775808)
#define INT64_MAX 9223372036854775807
#define UINT64_MAX 18446744073709551615

// Macros for integer constants
#define INT8_C(x) x
#define UINT8_C(x) x
#define INT16_C(x) x
#define UINT16_C(x) x
#define INT32_C(x) x
#define UINT32_C(x) x
#define INT64_C(x) x##LL
#define UINT64_C(x) x##ULL

// Macros for integer types
#define INTMAX_C(x) INT64_C(x)
#define UINTMAX_C(x) UINT64_C(x)
#define INTPTR_C(x) INT32_C(x)
#define UINTPTR_C(x) UINT32_C(x)
#define INTMAX_MAX INT64_MAX
#define UINTMAX_MAX UINT64_MAX
#define INTPTR_MAX INT32_MAX
#define UINTPTR_MAX UINT32_MAX

#endif  // _STDINT_H