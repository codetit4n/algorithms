## Practice questions

> These questions are from Introduction to Algorithms by CLRS (4th edition)

Q1. Suppose that for inputs of size n on a particular computer, insertion sort
runs in 8n<sup>2</sup> steps and merge sort runs in 64 n lg n steps. For which
values of n does insertion sort beat merge sort?

Ans.

Insertion sort = 8n<sup>2</sup>
Merge sort = 64 n lg n

For insertion sort to beat merge sort the condition will be: 8n<sup>2</sup> $\lt$ 64 n lg n

Code: [1.py](./1.py)

Execute: `python3 1.py`
