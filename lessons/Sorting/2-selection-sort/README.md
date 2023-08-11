# Selection Sort

### Run code

- Sort in [increasing order](./selection_sort_inc.cpp): `sh increasing.sh`
- Sort in [decreasing order](./selection_sort_dec.cpp): `sh decreasing.sh`

### Notes:

- Time complexity: O(n<sup>2</sup>)
- Selection sort works best on small number of elements.
- Think of array as 2 arrays with initially just first element in left array and rest in the right array.
- It selects the smallest/largest element from right array and swaps it with the element at its rightful
  position on the left array.
- At all times left side of the array will be sorted.
