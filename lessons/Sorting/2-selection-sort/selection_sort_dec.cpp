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
    // assume the first element is the largest
    int largestIndex = i;
    // iterate through the rest of the array and select an element larger than
    // the assumed element
    for (int j = i + 1; j < len; j++) {
      if (arr[j] > arr[largestIndex]) {
        largestIndex = j;
      }
    }
    // swap the largest selected element with the assumed element
    int tmp = arr[i];
    arr[i] = arr[largestIndex];
    arr[largestIndex] = tmp;
  }
  cout << endl << "Output: ";
  display(arr, len);
  cout << endl;
  return 0;
}
