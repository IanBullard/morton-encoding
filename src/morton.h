#pragma once

#include <stdint.h>
#include <limits.h>

uint64_t morton_for(uint64_t x, uint64_t y, uint64_t z);

uint64_t morton_lut(uint64_t x, uint64_t y, uint64_t z);

uint64_t morton_magic(uint64_t x, uint64_t y, uint64_t z);

inline void morton_decode(uint64_t morton, unsigned int& x, unsigned int& y, unsigned int& z){
	x = 0;
	y = 0;
	z = 0;
	for (uint64_t i = 0; i < (sizeof(uint64_t)* CHAR_BIT) / 3; ++i) {
		x |= ((morton & (uint64_t(1ull) << uint64_t((3ull * i) + 0ull))) >> uint64_t(((3ull * i) + 0ull) - i));
		y |= ((morton & (uint64_t(1ull) << uint64_t((3ull * i) + 1ull))) >> uint64_t(((3ull * i) + 1ull) - i));
		z |= ((morton & (uint64_t(1ull) << uint64_t((3ull * i) + 2ull))) >> uint64_t(((3ull * i) + 2ull) - i));
	}
}
