#include <string.h>

// Copy a string
void *memcpy(void *dest, const void *src, size_t n) {
    char *d = dest;
    const char *s = src;
    while (n--) {
        *d++ = *s++;
    }
    return dest;
}

void *memmove(void *dest, const void *src, size_t n) {
    char *d = dest;
    const char *s = src;
    if (d < s) {
        while (n--) {
            *d++ = *s++;
        }
    } else {
        d += n;
        s += n;
        while (n--) {
            *--d = *--s;
        }
    }
    return dest;
}

// Concatenate two strings
char *strcpy(char *dest, const char *src) {
    char *d = dest;
    while ((*d++ = *src++));
    return dest;
}

char *strncpy(char *dest, const char *src, size_t n) {
    char *d = dest;
    while (n--) {
        *d++ = *src++;
    }
    *d = '\0';
    return dest;
}

// Compare two strings
int strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

int strncmp(const char *s1, const char *s2, size_t n) {
    while (n--) {
        if (*s1 != *s2) {
            return *s1 - *s2;
        }
        s1++;
        s2++;
    }
    return 0;
}

// Find the length of a string
size_t strlen(const char *s) {
    size_t n = 0;
    while (*s++) {
        n++;
    }
    return n;
}

// Find the first occurrence of a character in a string
char *strchr(const char *s, int c) {
    while (*s) {
        if (*s == c) {
            return (char *)s;
 }
        s++;
    }
    return NULL;
}

char *strrchr(const char *s, int c) {
    char *last = NULL;
    while (*s) {
        if (*s == c) {
            last = (char *)s;
        }
        s++;
    }
    return last;
}

// Find the first occurrence of a substring in a string
char *strstr(const char *haystack, const char *needle) {
    size_t n = strlen(needle);
    while (*haystack) {
        if (strncmp(haystack, needle, n) == 0) {
            return (char *)haystack;
        }
        haystack++;
    }
    return NULL;
}

// Split a string into tokens
char *strtok(char *str, const char *delim) {
    static char *last = NULL;
    if (str) {
        last = str;
    }
    if (!last) {
        return NULL;
    }
    while (*last) {
        if (strchr(delim, *last)) {
            *last++ = '\0';
            return last;
        }
        last++;
    }
    return NULL;
}

// Convert a string to an integer
int atoi(const char *nptr) {
    int sign = 1;
    int num = 0;
    while (*nptr == ' ') {
        nptr++;
    }
    if (*nptr == '-') {
        sign = -1;
        nptr++;
    } else if (*nptr == '+') {
        nptr++;
    }
    while (*nptr >= '0' && *nptr <= '9') {
        num = num * 10 + (*nptr - '0');
        nptr++;
    }
    return sign * num;
}

// Convert a string to a long integer
long atol(const char *nptr) {
    long sign = 1;
    long num = 0;
    while (*nptr == ' ') {
        nptr++;
    }
    if (*nptr == '-') {
        sign = -1;
        nptr++;
    } else if (*nptr == '+') {
        nptr++;
    }
    while (*nptr >= '0' && *nptr <= '9') {
        num = num * 10 + (*nptr - '0');
        nptr++;
    }
    return sign * num;
}

// Convert a string to a long long integer
long long atoll(const char *nptr) {
    long long sign = 1;
    long long num = 0;
    while (*nptr == ' ') {
        nptr++;
    }
    if (*nptr == '-') {
        sign = -1;
        nptr++;
    } else if (*nptr == '+') {
        nptr++;
    }
    while (*nptr >= '0' && *nptr <= '9') {
        num = num * 10 + (*nptr - '0');
        nptr++;
    }
    return sign * num;
}

// Convert a string to a floating-point number
double atof(const char *nptr) {
    double sign = 1;
    double num = 0;
    double frac = 0;
    int exp = 0;
    while (*nptr == ' ') {
        nptr++;
    }
    if (*nptr == '-') {
        sign = -1;
        nptr++;
    } else if (*nptr == '+') {
        nptr++;
    }
    while (*nptr >= '0' && *nptr <= '9') {
        num = num * 10 + (*nptr - '0');
        nptr++;
    }
    if (*nptr == '.') {
        nptr++;
        while (*nptr >= '0' && *nptr <= '9') {
            frac = frac * 10 + (*nptr - '0');
            nptr++;
            exp--;
        }
    }
    if (*nptr == 'e' || *nptr == 'E') {
        nptr++;
        if (*nptr == '-') {
            exp = -exp;
            nptr++;
        } else if (*nptr == '+') {
            nptr++;
        }
        while (*nptr >= '0' && *nptr <= '9') {
            exp = exp * 10 + (*nptr - '0');
            nptr++;
        }
    }
    return sign * (num + frac * pow(10, exp));
}

// Convert a string to a double-precision floating-point number
double strtod(const char *nptr, char **endptr) {
    double sign = 1;
    double num = 0;
    double frac = 0;
    int exp = 0;
    while (*nptr == ' ') {
        nptr++;
    }
    if (*nptr == '-') {
        sign = -1;
        nptr++;
    } else if (*nptr == '+') {
        nptr++;
    }
    while (*nptr >= '0' && *nptr <= '9') {
        num = num * 10 + (*nptr - '0');
        nptr++;
    }
    if (*nptr == '.') {
        nptr++;
        while (*nptr >= '0' && *nptr <= '9') {
            frac = frac * 10 + (*nptr - '0');
            nptr++;
            exp--;
        }
    }
    if (*nptr == 'e' || *nptr == 'E') {
        nptr++;
        if (*nptr == '-') {
            exp = -exp;
            nptr++;
        } else if (*nptr == '+') {
            nptr++;
        }
        while (*nptr >= '0' && *nptr <= '9') {
            exp = exp * 10 + (*nptr - '0');
            nptr++;
        }
    }
    if (endptr) {
        *endptr = (char *)nptr;
    }
    return sign * (num + frac * pow(10, exp));
}

// Convert a string to a long double-precision floating-point number
long double strtold(const char *nptr, char **endptr) {
    long double sign = 1;
    long double num = 0;
    long double frac = 0;
    int exp = 0;
    while (*nptr == ' ') {
        nptr++;
    }
    if (*nptr == '-') {
        sign = -1;
        nptr++;
    } else if (*nptr == '+') {
        nptr++;
    }
    while (*nptr >= '0' && *nptr <= '9') {
        num = num * 10 + (*nptr - '0');
        nptr++;
    }
    if (*nptr == '.') {
        nptr++;
        while (*nptr >= '0' && *nptr <= '9') {
            frac = frac * 10 + (*nptr - '0');
            nptr++;
            exp--;
        }
    }
    if (*nptr == 'e' || *nptr == 'E') {
        nptr++;
        if (*nptr == '-') {
            exp = -exp;
            nptr++;
        } else if (*nptr == '+') {
            nptr++;
        }
        while (*nptr >= '0' && *nptr <= '9') {
            exp = exp * 10 + (*nptr - '0');
            nptr++;
        }
    }
    if (endptr) {
        *endptr = (char *)nptr;
    }
    return sign * (num + frac * pow(10, exp));
}

// Convert a string to an integer with base
int strtol(const char *nptr, char **endptr, int base) {
    int sign = 1;
    int num = 0;
    while (*nptr == ' ') {
        nptr++;
    }
    if (*nptr == '-') {
        sign = -1;
        nptr++;
    } else if (*nptr == '+') {
        nptr++;
    }
    while (*nptr) {
        int digit = 0;
        if (*nptr >= '0' && *nptr <= '9') {
            digit = *nptr - '0';
        } else if (*nptr >= 'A' && *nptr <= 'Z') {
            digit = *nptr - 'A' + 10;
        } else if (*nptr >= 'a' && *nptr <= 'z') {
            digit = *nptr - 'a' + 10;
        } else {
            break;
        }
        if (digit >= base) {
            break;
        }
        num = num * base + digit;
        nptr++;
    }
    if (endptr) {
        *endptr = (char *)nptr;
    }
    return sign * num;
}

// Convert a string to a long integer with base
long strtol(const char *nptr, char **endptr, int base) {
    long sign = 1;
    long num = 0;
    while (*nptr == ' ') {
        nptr++;
    }
    if (*nptr == '-') {
        sign = -1;
        nptr++;
    } else if (*nptr == '+') {
        nptr++;
    }
    while (*nptr) {
        int digit = 0;
        if (*nptr >= '0' && *nptr <= '9') {
            digit = *nptr - '0';
        } else if (*nptr >= 'A' && *nptr <= 'Z') {
            digit = *nptr - 'A' + 10;
        } else if (*nptr >= 'a' && *nptr <= 'z') {
            digit = *nptr - 'a' + 10;
        } else {
            break;
        }
        if (digit >= base) {
            break;
        }
        num = num * base + digit;
        nptr++;
    }
    if (endptr) {
        *endptr = (char *)nptr;
    }
    return sign * num;
}

// Convert a string to a long long integer with base
long long strtoll(const char *nptr, char **endptr, int base) {
    long long sign = 1;
    long long num = 0;
    while (*nptr == ' ') {
        nptr++;
    }
    if (*nptr == '-') {
        sign = -1;
        nptr++;
    } else if (*nptr == '+') {
        nptr++;
    }
    while (*nptr) {
        int digit = 0;
        if (*nptr >= '0' && *nptr <= '9') {
            digit = *nptr - '0';
        } else if (*nptr >= 'A' && *nptr <= 'Z') {
            digit = *nptr - 'A' + 10;
        } else if (*nptr >= 'a' && *nptr <= 'z') {
            digit = *nptr - 'a' + 10;
        } else {
            break;
        }
        if (digit >= base) {
            break;
        }
        num = num * base + digit;
        nptr++;
    }
    if (endptr) {
        *endptr = (char *)nptr;
    }
    return sign * num;
}

// Convert a string to a floating-point number with base
double strtof(const char *nptr, char **endptr) {
    double sign = 1;
    double num = 0;
    double frac = 0;
    int exp = 0;
    while (*nptr == ' ') {
        nptr++;
    }
    if (*nptr == '-') {
        sign = -1;
        nptr++;
    } else if (*nptr == '+') {
        nptr++;
    }
    while (*nptr >= '0' && *nptr <= '9') {
        num = num * 10 + (*nptr - '0');
        nptr++;
    }
    if (*nptr == '.') {
        nptr++;
        while (*nptr >= '0' && *nptr <= '9') {
            frac = frac * 10 + (*nptr - '0');
            nptr++;
            exp--;
        }
    }
    if (*nptr == 'e' || *nptr == 'E') {
        nptr++;
        if (*nptr == '-') {
            exp = -exp;
            nptr++;
        } else if (*nptr == '+') {
            nptr++;
        }
        while (*nptr >= '0' && *nptr <= '9') {
            exp = exp * 10 + (*nptr - '0');
            nptr++;
        }
    }
    if (endptr) {
        *endptr = (char *)nptr;
    }
    return sign * (num + frac * pow(10, exp));
}

// Convert a string to a double-precision floating-point number with base
double strtod(const char *nptr, char **endptr) {
    double sign = 1;
    double num = 0;
    double frac = 0;
    int exp = 0;
    while (*nptr == ' ') {
        nptr++;
    }
    if (*nptr == '-') {
        sign = -1;
        nptr++;
    } else if (*nptr == '+') {
        nptr++;
    }
    while (*nptr >= '0' && *nptr <= '9') {
        num = num * 10 + (*nptr - '0');
        nptr++;
    }
    if (*nptr == '.') {
        nptr++;
        while (*nptr >= '0' && *nptr <= '9') {
            frac = frac * 10 + (*nptr - '0');
            nptr++;
            exp--;
        }
    }
    if (*nptr == 'e' || *nptr == 'E') {
        nptr++;
        if (*nptr == '-') {
            exp = -exp;
            nptr++;
        } else if (*nptr == '+') {
            nptr++;
        }
        while (*nptr >= '0' && *nptr <= '9') {
            exp = exp * 10 + (*nptr - '0');
            nptr++;
        }
    }
    if (endptr) {
        *endptr = (char *)nptr;
    }
    return sign * (num + frac * pow(10, exp));
}

// Convert a string to a long double-precision floating-point number with base
long double strtold(const char *nptr, char **endptr) {
    long double sign = 1;
    long double num = 0;
    long double frac = 0;
    int exp = 0;
    while (*nptr == ' ') {
        nptr++;
    }
    if (*nptr == '-') {
        sign = -1;
        nptr++;
    } else if (*nptr == '+') {
        nptr++;
    }
    while (*nptr >= '0' && *nptr <= '9') {
        num = num * 10 + (*nptr - '0');
        nptr++;
    }
    if (*nptr == '.') {
        nptr++;
        while (*nptr >= '0' && *nptr <= '9') {
            frac = frac * 10 + (*nptr - '0');
            nptr++;
            exp--;
        }
    }
    if (*nptr == 'e' || *nptr == 'E') {
        nptr++;
        if (*nptr == '-') {
            exp = -exp;
            nptr++;
        } else if (*nptr == '+') {
            nptr++;
        }
        while (*nptr >= '0' && *nptr <= '9') {
            exp = exp * 10 + (*nptr - '0');
            nptr++;
        }
    }
    if (endptr) {
        *endptr = (char *)nptr;
    }
    return sign * (num + frac * pow(10, exp));
}