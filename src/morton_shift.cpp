#include <stdint.h>
#include <limits.h>
using namespace std;

// method to seperate bits from a given integer 3 positions apart
inline uint64_t splitBy3(uint64_t a)
{
   uint64_t x = a & 0x1fffff; // we only look at the first 21 bits
   x = (x | x << 32) & 0x1f00000000ffff;  // shift left 32 bits, OR with self, and 0000 0000'0001 1111'0000 0000'0000 0000'0000 0000'0000 0000'1111 1111'1111 1111
   x = (x | x << 16) & 0x1f0000ff0000ff;  // shift left 16 bits, OR with self, and 0000 0000'0001 1111'0000 0000'0000 0000'1111 1111'0000 0000'0000 0000'1111 1111
   x = (x | x << 8) & 0x100f00f00f00f00f; // shift left  8 bits, OR with self, and 0001 0000'0000 1111'0000 0000'1111 0000'0000 1111'0000 0000'1111 0000'0000 0000
   x = (x | x << 4) & 0x10c30c30c30c30c3; // shift left  4 bits, OR with self, and 0001 0000'1100 0011'0000 1100'0011 0000'1100 0011'0000 1100'0011 0001'0000 0000
   x = (x | x << 2) & 0x1249249249249249; // shift left  1 bits, OR with self, and 0001 0101'0101 0101'0101 0101'0101 0101'0101 0101'0101 0101'0101 0101'0101 0101
   return x;
}

uint64_t morton_magic(uint64_t x, uint64_t y, uint64_t z)
{
   uint64_t result = 0;
   result |= splitBy3(x) | splitBy3(y) << 1 | splitBy3(z) << 2;
   return result;
}
