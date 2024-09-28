## Practice questions

> These questions are from Introduction to Algorithms by CLRS (4th edition)

Q1. Suppose that for inputs of size n on a particular computer, insertion sort
runs in 8n<sup>2</sup> steps and merge sort runs in 64 n lg n steps. For which
values of n does insertion sort beat merge sort?

Ans.

Insertion sort = 8n<sup>2</sup>

Merge sort = 64 n lg n

For insertion sort to beat merge sort the condition will be: 8n<sup>2</sup> $\lt$ 64 n lg n

For n = 1, this condition is wrong but for n > 1 it will work.

Code: [1.py](./1.py)

Execute: `python3 1.py`

Solution: For values 2 $\le$ n $\le$ 43

---

Q2. What is the smallest value of n such that an algorithm whose running
time is 100n<sup>2</sup> runs faster than an algorithm whose running time is 2<sup>n</sup> on
the same machine?

Ans.

Algorithm 1 = 100n<sup>2</sup>

Algorithm 2 = 2<sup>n</sup>

For Algorithm 1 to run faster than Algorithm 2: 100n<sup>2</sup> < 2<sup>n</sup>. We need to
find the first time this happens.

Code: [2.py](./2.py)

Execute: `python3 2.py`

Solution: For n = 15

---
