#include "array.h"

#define LOG_ERROR
//#define LOG_INFO
//#define LOG_DEBUG

void create_array(ARRAY* a, size_t elementSize) {
    a->eAmount = 0;
    a->eSize = elementSize;
    a->ptr = NULL;
}
void _init_array(ARRAY* a) {
#ifdef LOG_INFO
    printf("[~] (qolc/array) initializing array\n");
#endif
    a->eAmount = 1;
    a->ptr = malloc(a->eSize);
    if(a->ptr == NULL) {
#ifdef LOG_ERROR
        puts("[-] (qolc/array) malloc failed\n");
#endif
        exit(0xc0000005);
    }
}
bool _initialized_array(ARRAY* a) {
#ifdef LOG_DEBUG
    printf("%p %zu %zu\n", a->ptr, a->eAmount, a->eSize);
#endif
    return a->ptr != NULL;
}
void _resize_array(ARRAY* a, long long change) {
#ifdef LOG_INFO
    printf("[~] (qolc/array) resizing array from %zu to %llu\n", a->eAmount, a->eAmount+change);
#endif
    void* temp;
    size_t newSize;
    if(a->ptr != NULL) {
        a->eAmount += change;
        newSize = a->eSize * a->eAmount;
        if(newSize == 0) {
            free(a->ptr);
            a->ptr = NULL;
        } else {
            temp = realloc(a->ptr, newSize);
            if(temp != NULL) {
                a->ptr = temp;
            } else {
#ifdef LOG_ERROR
                puts("[-] (qolc/array) realloc failed\n");
#endif
                exit(0xc0000005);
            }
        }
    }
}

void push_array(ARRAY* a, void* ptr) {
    if (!_initialized_array(a)) {
        _init_array(a);
    } else {
        _resize_array(a, 1);
    }
#ifdef LOG_DEBUG
    printf("%zu %zu\n", a->eAmount, a->eAmount-1);
#endif
    setval_array(a, a->eAmount-1, ptr);
}
void pop_array(ARRAY* a, void* target) {
    getval_array(a, a->eAmount-1, target);
    _resize_array(a, -1);
}
void setval_array(ARRAY* a, size_t index, void* ptr) {
    if (!_initialized_array(a)) {
        _init_array(a);
    }
    if(index >= a->eAmount) {
#ifdef LOG_ERROR
        printf("%zu, %zu", index, a->eAmount);
        puts("[-] (qolc/array) SET index greater than amount of values\n");
#endif
        exit(0xc0000005);
    }
    memcpy(a->ptr + (a->eSize * index), ptr, a->eSize);
}
void getval_array(ARRAY* a, size_t index, void* target) {
    if(index >= a->eAmount) {
#ifdef LOG_ERROR
        puts("[-] (qolc/array) GET index greater than amount of values\n");
#endif
        exit(0xc0000005);
    }
    memcpy(target, a->ptr + (a->eSize * index), a->eSize);
}
bool v_in_array(ARRAY* a, void* ptr) {
    for(size_t i = 0; i < a->eAmount; i++) {
        if(memcmp(a->ptr + (a->eSize * i), ptr, a->eSize) == 0) {
            return true;
        }
    }
    return false;
}
void pushb_array(ARRAY* a, void* ptr) {
    _resize_array(a, 1);

    void* temp = malloc(a->eSize);
    for(size_t i = a->eAmount-1; i > 0; i--) {
        getval_array(a, i-1, temp);
        setval_array(a, i, temp);
    }
    free(temp);
    setval_array(a, 0, ptr);
}
void popb_array(ARRAY* a, void* target) {
    getval_array(a, 0, target);
    remove_array(a, 0);
}

void remove_array(ARRAY* a, size_t index) {
    void* temp = malloc(a->eSize);
    for(size_t i = index+1; i < a->eAmount; i++) {
        getval_array(a, i, temp);
        setval_array(a, i-1, temp);
    }
    free(temp);
    _resize_array(a, -1);
}

size_t index_of(ARRAY* a, void* ptr) {
    for(size_t i = 0; i < a->eAmount; i++) {
        if(memcmp(a->ptr + (a->eSize * i), ptr, a->eSize) == 0) {
            return i;
        }
    }
    return -1;
}

void delete_array(ARRAY* a) {
    if(a->ptr != NULL) {
        free(a->ptr);
    }
    a->ptr = NULL;
    a->eSize = 0;
    a->eAmount = 0;
}
