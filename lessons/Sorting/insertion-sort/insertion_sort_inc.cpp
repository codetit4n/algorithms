// Insertion sort in increasing order

#include <iostream>
using namespace std;

void display(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    cout << arr[i] << " ";
  }
}

int main() {
  int arr[] = {5, 2, 7, -1, 2, 0, 9, 1};
  int len = sizeof(arr) / sizeof(int);
  cout << "Input: ";
  display(arr, len);

  int i = 1;
  while (i < len) {
    // pick and element to insert
    int to_insert = arr[i];
    int j = i - 1;
    // shift elements to the right till the correct position is found
    while (j >= 0 && to_insert < arr[j]) {
      arr[j + 1] = arr[j];
      j--;
    }
    // insert the element - j + 1 because j-- is done in the inner loop
    arr[j + 1] = to_insert;
    i++;
  }

  cout << endl << "Output: ";
  display(arr, len);
  cout << endl;
  return 0;
}
