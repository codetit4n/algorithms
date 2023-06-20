import math

# We need to find n where 100n^2 becomes < 2^n

n = 1

while 100 * n**2 > 2**n:
    n += 1

print("Min n for which Algorithm 1 is faster than Algorithm 2 is", n)
