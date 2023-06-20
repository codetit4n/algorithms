import math

# Condition 
# 8 n^2 < 64 n log2(n) for insertion sort to be faster than merge sort
# n < 8 * log2(n)

n = 2

while n < 8 * math.log(n,2):
    n += 1

print("Min value of n for which merge sort is faster than insertion sort: ",n)
