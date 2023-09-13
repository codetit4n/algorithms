// Simple mtrix multiplication - Takes O(n^3) time
#include <iostream>

using namespace std;

int main() {

  int m, n;
  cout << "Enter the size of the matrix A (m x n): ";
  cin >> m >> n;

  int p, q;
  cout << "Enter the size of the matrix B (p x q): ";
  cin >> p >> q;

  if (n != p) {
    cout << "Matrix multiplication not possible!" << endl;
    return 0;
  }

  int A[m][n], B[p][q], C[m][q];

  for (int i = 0; i < m; i++) {
    cout << "Enter the elements of row " << i + 1 << " of matrix A: " << endl;
    for (int j = 0; j < n; j++) {
      cin >> A[i][j];
    }
  }

  for (int i = 0; i < p; i++) {
    cout << "Enter the elements of row " << i + 1 << " of matrix B: " << endl;
    for (int j = 0; j < q; j++) {
      cin >> B[i][j];
    }
  }

  // initialize matrix C with 0
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < q; j++)
      C[i][j] = 0;
  }

  // multiply A and B and store in C
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < q; j++) {
      for (int k = 0; k < n; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  cout << "Matrix A is: " << endl;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << A[i][j] << " ";
    }
    cout << endl;
  }

  cout << "Matrix B is: " << endl;
  for (int i = 0; i < p; i++) {
    for (int j = 0; j < q; j++) {
      cout << B[i][j] << " ";
    }
    cout << endl;
  }

  cout << "Matrix C is: " << endl;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < q; j++) {
      cout << C[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl;

  return 0;
}
