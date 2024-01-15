// Bubble sort in increasing order

#include <iostream>
using namespace std;

void display(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {

  int arr[] = {5, 6, 0, 7, -2, 3, 1, 4, 8, 9};
  int len = sizeof(arr) / sizeof(int);

  cout << "Unsorted array: ";
  display(arr, len);

  // Needed for the case when the array is already sorted
  bool swapped = false;

  for (int i = 0; i < len; i++) {

    // After each pass, the largest element will be at the end
    for (int j = 0; j < len - i - 1; j++) {

      // Swap if the element found is greater than the next element
      if (arr[j] > arr[j + 1]) {
        int tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
        // set swapped to true to indicate that a swap occurred
        swapped = true;
      }
    }

    // If no elements were swapped during a pass, break out of loop
    if (!swapped) {
      break;
    }
  }

  cout << "Sorted array: ";
  display(arr, len);

  return 0;
}
