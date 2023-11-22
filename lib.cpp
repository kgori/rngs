#include "lib.h"

xorshift32::result_type xorshift32::operator()() {
    state ^= state << 13;
    state ^= state >> 17;
    state ^= state << 5;
    return state;
}

lcg::result_type lcg::operator()() {
    state = (state * a + c) % m;
    return state;
}

xorwow::result_type xorwow::operator()() {
    result_type t = state[4];

    /* Change places! */
    result_type s = state[0];
    state[4] = state[3];
    state[3] = state[2];
    state[2] = state[1];
    state[1] = s;

    t ^= t >> 2;
    t ^= t << 1;
    t ^= s ^ (s << 4);
    state[0] = t;

    /* Presumably counter is allowed (expected?) to overflow? */
    counter += 362437;

    return t + counter;
}
