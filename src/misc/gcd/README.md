# Greatest common divisor(GCD) algorithm

- Euclidian iterative: [gcd_euclidian_iterative.c](./gcd_euclidian_iterative.c)
- Euclidian recursive: [gcd_euclidian_recursive.c](./gcd_euclidian_recursive.c)

#### Example:

```text
Calculate GCD of 1220 and 516:

1220 %  516 = 188
516  %  188 = 140
188  %  140 = 48
140  %  48  = 44
48   %  44  = 4
44   %  4   = 0 (stop)

4 = GCD

```

#### Pseudo code for algorithm:

```text
Calculate GCD of a and b:

1. a % b = R
2. a = b and b = R
3. Repeat above until a % b is != 0

GCD = b

```
