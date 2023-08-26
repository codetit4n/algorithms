#include <iostream>
using namespace std;

// Display Array
void display(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}
long merge(int arr[], int start, int mid, int end) {
  long totalInversions = 0;
  // new array
  int mix[end - start + 1];

  int i = start;   // pointer for left arr
  int j = mid + 1; // pointer for right arr
  int k = 0;       // common ptr for both arr

  while (i <= mid && j <= end) {
    if (arr[i] <= arr[j]) {
      mix[k] = arr[i];
      i++; // since left element is smaller put it in mix array and increment
           // pointer
    } else {
      mix[k] = arr[j];
      j++; // since right element is smaller put it in mix array and increment
           // pointer
      totalInversions += mid - i + 1; // since right element is smaller than
                                      // left element, all the elements from
                                      // i+1 to mid will also be smaller than
                                      // right element
    }
    k++; // increment mix array pointer
  }

  // if left array is not empty
  while (i <= mid) {
    mix[k] = arr[i];
    i++;
    k++;
  }

  // if right array is not empty
  while (j <= end) {
    mix[k] = arr[j];
    j++;
    k++;
  }

  // copy mix array to original array
  for (int l = 0; l < end - start + 1; l++) {
    arr[start + l] = mix[l]; // start + l will give the correct index that needs
                             // to be updated
  }
  return totalInversions;
}

long countInversions(int arr[], int start, int end) {

  long totalInversions = 0;
  // base case
  if (start >= end) {
    return 0;
  }

  // Divide the array into two parts
  int mid = start + (end - start) / 2;
  // return countInversion(arr, start, end) + countInversion(arr, start, end);

  totalInversions = countInversions(arr, start, mid);
  totalInversions += countInversions(arr, mid + 1, end);
  totalInversions += merge(arr, start, mid, end);
  return totalInversions;
}

int main() {

  int arr[] = {7, 2, 4, 7, 1, 3, 64, 1, 9};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Array: ";
  display(arr, n);

  cout << "Inversion Count: " << countInversions(arr, 0, n - 1) << endl;
  return 0;
}
