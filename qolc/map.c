#include "map.h"

void create_map(MAP* m, size_t keysize, size_t valuesize) {
    m->kSize = keysize;
    m->vSize = valuesize;
    m->eAmount = 0;

    m->hashf = simple_hash;

    _init_map(m);
}

void _init_map(MAP* m) {
    m->eAmount = 1;

    create_array(&m->kArray, m->kSize);
    _init_array(&m->kArray);
    create_array(&m->vArray, m->vSize);
    _init_array(&m->vArray);
}
bool _initialized_map(MAP* m) {
    return m->kArray.ptr != NULL;
}

_Bool key_in_map(MAP* m, void* key) {
    return v_in_array(&m->kArray, key);
}
void set_map(MAP* m, void* key, void* value) {
    if(!key_in_map(m, key)) {
        push_array(&m->kArray, key);
        push_array(&m->vArray, value);
    }
}
void get_map(MAP* m, void* key, void* target) {
    size_t index;
    if(key_in_map(m, key)) {
        index = index_of(&m->kArray, key);
        getval_array(&m->vArray, index, target);
    }
}
void remove_map(MAP* m, void* key) {
    size_t index = index_of_k_map(m, key);
    if(index != -1) {
        remove_array(&m->kArray, index);
        remove_array(&m->vArray, index);
    }
}
size_t index_of_k_map(MAP* m, void* key) {
    return index_of(&m->kArray, key);
}
size_t index_of_v_map(MAP* m, void* value) {
    return index_of(&m->vArray, value);
}
void delete_map(MAP* m) {
    delete_array(&m->kArray);
    delete_array(&m->vArray);

    m->eAmount = 0;
    m->kSize = 0;
    m->vSize = 0;
}
