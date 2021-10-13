#include <stdint.h>
#include <limits.h>

using namespace std;

uint64_t morton_for(uint64_t x, uint64_t y, uint64_t z)
{
   uint64_t result = 0;
   for (uint64_t i = 0; i < (sizeof(uint64_t)* CHAR_BIT)/3; ++i) 
   {
      result |= ((x & ((uint64_t)1 << i)) <<  2*i)
             |  ((y & ((uint64_t)1 << i)) << (2*i + 1))
             |  ((z & ((uint64_t)1 << i)) << (2*i + 2));
   }
   return result;
}
