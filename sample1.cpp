#include <iostream>
#include "lib.h"
int main() {
    xorshift32 gen_xor{1020304};
    lcg        gen_lcg{2030405};
    xorwow     gen_wow{6543210};
    std::cout << gen_xor() << '\n';
    std::cout << gen_lcg() << '\n';
    std::cout << gen_wow() << '\n';
    return 0;
}
