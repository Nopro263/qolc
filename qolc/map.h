#ifndef QOLC_MAP_H
#define QOLC_MAP_H

#include <stdlib.h>
#include "hash.h"
#include "array.h"

typedef size_t MEMORY_HASH(void*, size_t);

typedef struct _MAP {
    ARRAY kArray;
    ARRAY vArray;
    size_t kSize;
    size_t vSize;
    size_t eAmount;
    MEMORY_HASH* hashf;
} MAP;

void create_map(MAP* m, size_t keysize, size_t valuesize);
void _init_map(MAP* m);
void set_map(MAP* m, void* key, void* value);
void get_map(MAP* m, void* key, void* target);
void remove_map(MAP* m, void* key);
void delete_map(MAP* m);
size_t index_of_k_map(MAP* m, void* key);
size_t index_of_v_map(MAP* m, void* value);

#include "map.c"
#endif //QOLC_MAP_H
