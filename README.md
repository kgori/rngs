RNGs
====

I didn't really know how random number generators worked, so I made a couple of basic ones:

```c++
#include <iostream>
#include "lib.h"
int main() {
    xorshift32 gen_xor{1020304};
    lcg        gen_lcg{2030405};
    std::cout << gen_xor() << '\n';
    std::cout << gen_lcg() << '\n';
}
```

They are compatible with the distribution generators in <random>:

```c++
#include <iostream>
#include <random>
#include "lib.h"
int main() {
    xorshift32 gen_xor{1020304};
    lcg        gen_lcg{2030405};
    std::uniform_real_distribution<> dst(0, 1);
    std::cout << dst(gen_xor) << '\n';
    std::cout << dst(gen_lcg) << '\n';
}
```
