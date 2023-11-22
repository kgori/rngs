#include <random>
#include <iostream>
#include "lib.h"

template<typename T>
requires std::uniform_random_bit_generator<T>
void check_rng(T rng) {

}

int main(int argc, char ** argv) {
    std::cout << "rnd" << std::endl;
    xorshift32 rng{1010203};
    check_rng(rng);
    
    std::uniform_real_distribution<> distrib(0, 1);
    for (int i = 0; i < 20000; i++) {
        std::cout << distrib(rng) << std::endl;
    }

    return 0;
}
