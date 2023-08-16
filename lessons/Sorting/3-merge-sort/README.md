# Merge sort

### About:

Two approaches here:

1. [Method 1](./method1): Return, send and create new arrays whenever required - Java
2. [Method 2](./method2): Use indexes instead of everytime sending, returning and creating the arrays - C++

### Notes:

- Time complexity: O(n\*log n)
- Follows divide and conquer approach.
- Must do three steps of divide and conquer approach:
  1. Divide: problem into smaller subproblems.
  2. Conquer: the subproblems by solving recusively.
  3. Combine: the subproblems solutions to form final solution.
- Merge sort approach:
  1. Divide array into 2 parts.
  2. Get both parts sorted via recursion.
  3. Merge the sorted parts.
