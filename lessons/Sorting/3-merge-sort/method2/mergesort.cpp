#include <iostream>
using namespace std;

void display(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    cout << arr[i] << " ";
  }
}

void merge(int arr[], int start, int mid, int end) {
  // new array
  int mix[end - start];

  int i = start; // pointer for left arr
  int j = mid;   // pointer for right arr
  int k = 0;     // common ptr for both arr

  while (i < mid && j < end) {
    if (arr[i] < arr[j]) {
      mix[k] = arr[i];
      i++; // since left element is smaller put it in mix array and increment
           // pointer
    } else {
      mix[k] = arr[j];
      j++; // since right element is smaller put it in mix array and increment
           // pointer
    }
    k++; // increment mix array pointer
  }

  // if left array is not empty
  while (i < mid) {
    mix[k] = arr[i];
    i++;
    k++;
  }

  // if right array is not empty
  while (j < end) {
    mix[k] = arr[j];
    j++;
    k++;
  }

  // copy mix array to original array
  for (int l = 0; l < end - start; l++) {
    arr[start + l] = mix[l]; // start + l will give the correct index that needs
                             // to be updated
  }
}

void mergesort(int arr[], int start, int end) {

  // Base condition - when array only as one element
  if (end - start == 1) {
    return;
  }

  // Divide the array into two parts
  int mid = start + (end - start) / 2;

  // Recursively sort the two parts
  mergesort(arr, start, mid);
  mergesort(arr, mid, end);
  // Merge the two sorted parts accordingly
  merge(arr, start, mid, end);
}

int main() {

  int arr[] = {4, 2, 1, 3, 5, 6, 7, 8, 9, 10};
  int len = sizeof(arr) / sizeof(int);
  cout << "Input: ";
  display(arr, len);

  mergesort(arr, 0, len);

  cout << endl << "Output: ";
  display(arr, len);
  cout << endl;
  return 0;
}
