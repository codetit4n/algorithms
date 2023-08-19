#include <iostream>
using namespace std;

// Recursive binary search
int binary_srch(int arr[], int start, int end, int target) {

  // Base condition
  if (start > end) {
    return -1;
  }

  int mid = start + (end - start) / 2; // similar to (start + end) / 2 but
                                       // prevents overflow

  if (target < arr[mid]) {
    return binary_srch(arr, start, mid - 1, target);
  }
  if (target > arr[mid]) {
    return binary_srch(arr, mid + 1, end, target);
  }
  return mid; // if target == arr[mid]
}

void display(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  cout << endl;
  int arr[] = {2, 4, 5, 6, 7, 8, 9, 10, 35, 67, 89, 90};
  int len = sizeof(arr) / sizeof(int);
  cout << "Test 1" << endl;
  cout << "Array: ";
  display(arr, len);
  int e = 500;
  cout << "Element to search: " << e << endl;
  int ans = binary_srch(arr, 0, len - 1, e);
  cout << "Element found at index: ";
  cout << ans << endl;
  cout << "---------------------------------" << endl;
  cout << "Test 2" << endl;
  int arr2[] = {2, 4, 5, 6, 7, 8, 9, 10, 35, 67, 89, 90};
  int len2 = sizeof(arr2) / sizeof(int);
  cout << "Array: ";
  display(arr2, len2);
  int e2 = 10;
  cout << "Element to search: " << e2 << endl;
  int ans2 = binary_srch(arr2, 0, len2 - 1, e2);
  cout << "Element found at index: ";
  cout << ans2 << endl;
  return 0;
}
