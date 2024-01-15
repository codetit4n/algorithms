#include <iostream>
using namespace std;

void display(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void insert(int arr[], int end) {

  // find the element to insert
  int to_insert = arr[end];
  int j = end - 1;
  // find the position to insert
  while (j >= 0 && to_insert < arr[j]) {
    arr[j + 1] = arr[j];
    j--;
  }
  // insert the element at correct position
  arr[j + 1] = to_insert;
}

void insertion_sort(int arr[], int end) {

  // Base condition - Only one element
  if (end == 1) {
    return;
  }
  // Decrease end by 1 - to sort first n-1 elements
  --end;
  // Recursive call to sort first n-1 elements
  insertion_sort(arr, end);
  // Insert last element at its correct position in sorted array
  insert(arr, end);
}

int main() {

  int arr[] = {4, -2, 5, 3, 1, 9, 8, 7, 6};
  int len = sizeof(arr) / sizeof(int);
  cout << "Before sorting: ";
  display(arr, len);

  insertion_sort(arr, len);

  cout << "After sorting: ";
  display(arr, len);

  return 0;
}
