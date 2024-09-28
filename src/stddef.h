#ifndef _STDDEF_H
#define _STDDEF_H

// NULL macro
#define NULL ((void *)0)

// size_t type
typedef unsigned int size_t;

// ptrdiff_t type
typedef int ptrdiff_t;

// wchar_t type
typedef int wchar_t;

// max_align_t type
typedef struct {
    long long __max_align_ll;
    long double __max_align_ld;
} max_align_t;

// offsetof macro
#define offsetof(type, member) ((size_t)&((type *)0)->member)

#endif  // _STDDEF_H