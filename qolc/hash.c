#include "hash.h"

size_t simple_hash(void* memory, size_t size) {
    size_t res = 0;
    char* _memory = memory;
    for(size_t i = 0; i < size; i++) {
        res += (_memory[i] << 3) * 3274210;
        res += (_memory[i] >> 4) * 87354123;
    }
    return res;
}