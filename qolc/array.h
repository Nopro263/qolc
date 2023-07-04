#ifndef QOLC_ARRAY_H
#define QOLC_ARRAY_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct _ARRAY {
    void* ptr;
    size_t eSize;
    size_t eAmount;
} ARRAY;

void create_array(ARRAY* a, size_t elementSize);
void setval_array(ARRAY* a, size_t index, void* ptr);
void getval_array(ARRAY* a, size_t index, void* target);
void remove_array(ARRAY* a, size_t index);
void push_array(ARRAY* a, void* ptr);
void pop_array(ARRAY* a, void* target);
void pushb_array(ARRAY* a, void* ptr); // Same as pop_array but from the bottom (e.g. 0)
void popb_array(ARRAY* a, void* target); // Same as push_array but from the bottom (e.g. 0)
void delete_array(ARRAY* a);
void _init_array(ARRAY* a);
void _resize_array(ARRAY* a, long long change);
bool _initialized_array(ARRAY* a);
bool v_in_array(ARRAY* a, void* ptr);
size_t index_of(ARRAY* a, void* ptr);

#include "array.c"
#endif //QOLC_ARRAY_H
