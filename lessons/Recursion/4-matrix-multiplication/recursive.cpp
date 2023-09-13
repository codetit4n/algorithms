// Simple mtrix multiplication - Takes O(n^3) time
#include <iostream>

using namespace std;

void multiply(int m, int n, int A[m][n], int p, int q, int B[p][q],
              int C[m][q]) {
  // @todo - complete this
}

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
  // @todo - complete this

  cout << endl;

  return 0;
}
