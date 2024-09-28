#ifndef _STRING_H
#define _STRING_H

#include <stddef.h>

// Copy a string
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);

// Concatenate two strings
char *strcpy(char *dest, const char *src);
char *strncpy(char *dest, const char *src, size_t n);

// Compare two strings
int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);

// Find the length of a string
size_t strlen(const char *s);

// Find the first occurrence of a character in a string
char *strchr(const char *s, int c);
char *strrchr(const char *s, int c);

// Find the first occurrence of a substring in a string
char *strstr(const char *haystack, const char *needle);

// Split a string into tokens
char *strtok(char *str, const char *delim);

// Convert a string to an integer
int atoi(const char *nptr);

// Convert a string to a long integer
long atol(const char *nptr);

// Convert a string to a long long integer
long long atoll(const char *nptr);

// Convert a string to a floating-point number
double atof(const char *nptr);

// Convert a string to a double-precision floating-point number
double strtod(const char *nptr, char **endptr);

// Convert a string to a long double-precision floating-point number
long double strtold(const char *nptr, char **endptr);

// Convert a string to an integer with base
int strtol(const char *nptr, char **endptr, int base);

// Convert a string to a long integer with base
long strtol(const char *nptr, char **endptr, int base);

// Convert a string to a long long integer with base
long long strtoll(const char *nptr, char **endptr, int base);

// Convert a string to a floating-point number with base
double strtof(const char *nptr, char **endptr);

// Convert a string to a double-precision floating-point number with base
double strtod(const char *nptr, char **endptr);

// Convert a string to a long double-precision floating-point number with base
long double strtold(const char *nptr, char **endptr);

#endif  // _STRING_H