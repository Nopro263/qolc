#include "utils.h"

int imin(int a, int b) {
    return a < b ? a : b;
}
int imax(int a, int b) {
    return a > b ? a : b;
}

unsigned long long ullmin(unsigned long long a, unsigned long long b) {
    return a < b ? a : b;
}
unsigned long long ullmax(unsigned long long a, unsigned long long b) {
    return a > b ? a : b;
}