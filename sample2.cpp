#include <iostream>
#include <random>
#include "lib.h"

int main() {
    xorshift32 gen_xor{1020304};
    lcg        gen_lcg{2030405};
    std::uniform_real_distribution<> dst(0, 1);
    std::cout << dst(gen_xor) << '\n';
    std::cout << dst(gen_lcg) << '\n';
    return 0;
}
