#include "morton.h"

#include <cassert>
#include <random>

void verify(const char* left_name, uint64_t left, const char* right_name, uint64_t right)
{
    if(left != right)
    {
        printf_s("%16s = %16llX\n%16s = %16llX\n\n");
    }
}

int main(int argc, char** argv)
{
    constexpr uint64_t min = 0;
    constexpr uint64_t max = (1<<21)-1;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);

    constexpr int num_tests = 10000;

    uint64_t x, y, z;
    unsigned int decode_x, decode_y, decode_z;
    uint64_t result_for, result_magic, result_lut;
    for(int i=0; i<num_tests; ++i)
    {
        x = distrib(gen);
        y = distrib(gen);
        z = distrib(gen);

        result_for = morton_for(x, y, z);
        result_magic = morton_magic(x, y, z);
        result_lut = morton_lut(x, y, z);

        verify("for", result_for, "magic", result_magic);
        verify("for", result_for, "lut", result_lut);

        morton_decode(result_for, decode_x, decode_y, decode_z);
        verify("x", x, "decode", decode_x);
        verify("y", y, "decode", decode_y);
        verify("z", z, "decode", decode_z);
    }

    return 0;
}