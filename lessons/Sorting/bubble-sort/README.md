# Bubble Sort

### Run code

- Sort in [increasing order](./bubble_sort_inc.cpp): `sh increasing.sh`
- Sort in [decreasing order](./bubble_sort_dec.cpp): `sh decreasing.sh`

### Notes

- Time complexity: O(n<sup>2</sup>)
- It is also known as sinking sort or exchange sort.
- Need nested loops for this.
- Compare each element with the adjacent element in the inner loop and swap if needed.
- With every pass of the outer loop the largest element will come at the end.
- So, after every iteration of the outer loop one element is in its correct position and hence not needed to be compared
  in the next iteration.
- If in any iteration of the inner loop no swap happens, it means the array is sorted so we can break the loop.
