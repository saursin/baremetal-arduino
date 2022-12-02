#pragma once

#define bitset(x, n)    x | (1 << n)
#define bitclear(x, n)  x & ~(1 << n)
#define bitflip(x, n)   x ^ (1 << n)
#define bitcheck(x, n)  x & (1 << n)