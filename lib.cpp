#include "lib.h"

uint_fast32_t xorshift32::operator()() {
    state ^= state << 13;
    state ^= state >> 17;
    state ^= state << 5;
    return state;
}

uint_fast32_t lcg::operator()() {
    state = (state * a + c) % m;
    return state;
}
