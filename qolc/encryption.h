#ifndef QOLC_ENCRYPTION_H
#define QOLC_ENCRYPTION_H

#include <stdlib.h>

size_t len_xor(void* key, size_t keylen, void* plain, size_t plainlen);
void enc_xor(void* key, size_t keylen, void* plain, size_t plainlen, void* target);
void dec_xor(void* key, size_t keylen, void* plain, size_t plainlen, void* target);

#include "encryption.c"

#endif //QOLC_ENCRYPTION_H
