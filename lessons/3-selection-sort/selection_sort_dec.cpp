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

    int largestIndex = i;
    for (int j = i + 1; j < len; j++) {
      if (arr[j] > arr[largestIndex]) {
        largestIndex = j;
      }
    }
    int tmp = arr[i];
    arr[i] = arr[largestIndex];
    arr[largestIndex] = tmp;
  }
  cout << endl << "Output: ";
  display(arr, len);
  cout << endl;
  return 0;
}
