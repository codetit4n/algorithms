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
    int to_insert = arr[i];
    int j = i - 1;
    while (j >= 0 && to_insert < arr[j]) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = to_insert;
    i++;
  }

  cout << endl << "Output: ";
  display(arr, len);
  cout << endl;
  return 0;
}
