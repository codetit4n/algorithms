#include <iostream>
using namespace std;

// ------------ IGNORE FUNCTIONS BELOW ------------ //
// The below functions are just helper functions    //

// Display Array
void display(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

// Binary Search
int binarySearch(int arr[], int l, int r, int x) {
  while (l <= r) {
    int m = l + (r - l) / 2;

    if (arr[m] == x)
      return m;

    if (arr[m] < x)
      l = m + 1;

    else
      r = m - 1;
  }

  return -1;
}

// Merge Sort
void mergeSort(int arr[], int l, int r) {
  if (l >= r)
    return;

  int m = l + (r - l) / 2;
  mergeSort(arr, l, m);
  mergeSort(arr, m + 1, r);

  int i = l, j = m + 1, k = 0;
  int temp[r - l + 1];

  while (i <= m && j <= r) {
    if (arr[i] <= arr[j])
      temp[k++] = arr[i++];
    else
      temp[k++] = arr[j++];
  }

  while (i <= m)
    temp[k++] = arr[i++];

  while (j <= r)
    temp[k++] = arr[j++];

  for (int p = l; p <= r; p++)
    arr[p] = temp[p - l];
}

// ------------ IGNORE FUNCTIONS ABOVE ------------ //
// The above functions are just helper functions    //

// Function to find if there are two elements whose sum is equal to the given in
// O(nlogn) time
int srch(int S[], int n, int x) {

  mergeSort(S, 0, n - 1); // Sort the array - O(nlogn)
  cout << "Sorted Array: ";
  display(S, n);

  for (int i = 0; i < n; i++) {
    int index =
        binarySearch(S, 0, n, x - S[i]); // search for x - S[i] - O(logn)

    if (index != i && index != -1) { // if found and not the same index
      return true;
    }
  }

  return false;
}

// --------------- DRIVER CODE --------------- //

int main() {

  cout << endl << "TEST CASE 1" << endl;

  int S[] = {1, 4, 45, 6, 10, -8};
  int n = sizeof(S) / sizeof(int);

  cout << "Array: ";
  display(S, n);

  int x = 500000;
  cout << "Value of x: " << x << endl;

  if (srch(S, n, x))
    cout << "Found" << endl << endl;
  else
    cout << "Not Found" << endl << endl;

  cout << "-------------------------" << endl;
  cout << endl << "TEST CASE 2" << endl;

  int S1[] = {7, 4, 45, 6, -2, 10, 8};
  int n1 = sizeof(S1) / sizeof(int);

  cout << "Array: ";
  display(S1, n1);

  int x1 = 16;
  cout << "Value of x: " << x1 << endl;

  if (srch(S1, n1, x1))
    cout << "Found" << endl << endl;
  else
    cout << "Not Found" << endl << endl;

  return 0;
}
