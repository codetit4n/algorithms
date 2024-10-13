# Rotate an Array by d – Counterclockwise or Left

```
Given an array of integers arr[] of size n, the task is to rotate the
array elements to the left by d positions.

Example:
Input: arr[] = {1, 2, 3, 4, 5, 6}, d = 2
Output: {3, 4, 5, 6, 1, 2}
```

- Naive approach: [`rotate_left_naive.c`](./rotate_left_naive.c)
- Temporary array approach: [`rotate_left_tmp.c`](./rotate_left_tmp.c)
- Juggling approach: [`rotate_left_juggling.c`](./rotate_left_juggling.c)
- Reversal approach: [`rotate_left_reversal.c`](./rotate_left_reversal.c)

### Complexities

- Time complexity:
  - `O(n * d)` for naive approach
  - `O(n)` for other approaches
- Space complexity:
  - `O(n)` for temporary array approach
  - `O(1)` for other approaches
