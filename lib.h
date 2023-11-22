#include <stdint.h>

class xorshift32 {
    uint_fast32_t state;

public:
    using result_type = uint_fast32_t;

    xorshift32(uint_fast32_t seed) : state(seed) {}

    uint_fast32_t operator()(); 

    static constexpr uint_fast32_t min() { return 0; }

    static constexpr uint_fast32_t max() { return UINT32_MAX; }
};

class lcg {
    uint_fast32_t state;
    static constexpr uint_fast32_t a { 12345 };
    static constexpr uint_fast32_t c { 1103515245 };
    static constexpr uint_fast32_t m { 2147483648 }; // (1 << 31) - 1

public:
    using result_type = uint_fast32_t;

    lcg(uint_fast32_t seed) : state(seed) {}

    uint_fast32_t operator()();

    static constexpr uint_fast32_t min() { return 0; }

    static constexpr uint_fast32_t max() { return m - 1; }
};

