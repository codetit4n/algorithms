#include <iostream>
using namespace std;

// Display Array
void display(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main() {

  int arr[] = {1, 5, 2, 3, 4};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Array: ";
  display(arr, n);

  // @todo: Add code here

  return 0;
}
