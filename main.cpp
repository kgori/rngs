#include <random>
#include <iostream>
#include "lib.h"

/* This doesn't do anything except make the
*  compiler confirm that the T is a valid RNG. */
template<typename T>
requires std::uniform_random_bit_generator<T>
void check_rng(T rng) {}

/* What else would you do with a random number generator? 
*  Generate a bunch of random numbers. */
int main(int argc, char ** argv) {
    xorshift32 rng{1010203};
    check_rng(rng);
    
    std::uniform_real_distribution<> distrib(0, 1);
    for (int i = 0; i < 20000; i++) {
        std::cout << distrib(rng) << std::endl;
    }

    return 0;
}
