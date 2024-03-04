#pragma once
#include <stddef.h>
#include <stdio.h>
#include <assert.h>
#include <SmartPointer.h>

#define MAX(a,b)             \
({                           \
    __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a > _b ? _a : _b;       \
})

#define MIN(a,b)             \
({                           \
    __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a < _b ? _a : _b;       \
})






int max_diff(size_t n, size_t m, int* number_steps,int **array);
