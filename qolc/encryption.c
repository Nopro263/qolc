#include "encryption.h"

#include "utils.h"

size_t len_xor(void* key, size_t keylen, void* plain, size_t plainlen) {
    return ullmin(keylen, plainlen);
}
void enc_xor(void* key, size_t keylen, void* plain, size_t plainlen, void* target) {
    size_t max = ullmin(keylen, plainlen);
    char* _target = target;
    char* _key = key;
    char* _plain = plain;

    for(size_t i = 0; i < max; i++) {
        _target[i] = _plain[i] ^ _key[i];
    }
}
void dec_xor(void* key, size_t keylen, void* plain, size_t plainlen, void* target) {
    enc_xor(key, keylen, plain, plainlen, target);
}