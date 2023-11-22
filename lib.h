#include <stdint.h>
#include <initializer_list>
#include <iostream>
#include <iterator>

class xorshift32 {
public:
    using result_type = uint_fast32_t;

    xorshift32(result_type seed) : state(seed) {}

    result_type operator()();

    static constexpr result_type min() { return 0; }

    static constexpr result_type max() { return UINT32_MAX; }

private:
    result_type state;
};

class lcg {
public:
    using result_type = uint_fast32_t;

    lcg(result_type seed) : state(seed) {}

    result_type operator()();

    static constexpr result_type min() { return 0; }

    static constexpr result_type max() { return m - 1; }

private:
    result_type state;
    static constexpr result_type a { 12345 };
    static constexpr result_type c { 1103515245 };
    static constexpr result_type m { 2147483648 }; // (1 << 31) - 1
};

class xorwow {
    static constexpr std::size_t SIZE = 5;
public:
    using result_type = uint_fast32_t;

    xorwow(result_type seed) {
        state[0] = seed;
        lcg gen(seed);
        for (std::size_t i = 1; i < SIZE; ++i) {
            state[i] = gen();
        }
    }

    xorwow(std::initializer_list<result_type> seed) {
        std::size_t i{0};
        for (result_type s : seed) {
            state[i++] = s;
            if (i == SIZE) { break; }
        }
        if (i < SIZE) {
            lcg gen(state[0]);
            for (; i < SIZE; ++i) {
                state[i] = gen();
            }
        }
    }

    result_type operator()();

    static constexpr result_type min() { return 0; }

    static constexpr result_type max() { return UINT32_MAX; }

private:
    result_type state[SIZE]{ 0 };
    result_type counter{ 0 };
};

