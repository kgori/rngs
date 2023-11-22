#include <iostream>
#include "lib.h"
int main() {
    xorshift32 gen_xor{1020304};
    lcg        gen_lcg{2030405};
    std::cout << gen_xor() << '\n';
    std::cout << gen_lcg() << '\n';
    return 0;
}
