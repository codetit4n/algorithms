// Selection sort in increasing order

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

  for (int i = 0; i < len - 1; i++) {
    // assume the first element is the smallest
    int smallestIndex = i;
    // iterate through the rest of the array and select an element smaller than
    // the assumed element
    for (int j = i + 1; j < len; j++) {
      // if found, update the index of the smallest element
      if (arr[j] < arr[smallestIndex]) {
        smallestIndex = j;
      }
    }
    // swap the smallest selected element with the assumed element
    int tmp = arr[i];
    arr[i] = arr[smallestIndex];
    arr[smallestIndex] = tmp;
  }
  cout << endl << "Output: ";
  display(arr, len);
  cout << endl;
  return 0;
}
