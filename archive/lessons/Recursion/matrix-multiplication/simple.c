// Simple Recursive mtrix multiplication - Takes O(n^3) time
#include <stdio.h>

void multiply(int, int, int A[][10], int, int, int B[][10], int C[][10]);
void display(int, int, int C[][10]);

int main() {

  int A[10][10], B[10][10], C[10][10] = {0}; // C is the resultant matrix

  int m, n, p, q, i, j, k;

  printf("Enter rows and columns for matrix A: ");
  scanf("%d %d", &m, &n);

  printf("Enter rows and columns for matrix B: ");
  scanf("%d %d", &p, &q);

  if (n != p) {
    printf("Matrices cannot be multiplied!\n");
    return 0;
  } else {

    for (i = 0; i < m; i++) {
      printf("Enter elements for row %d of matrix A:\n", i + 1);
      for (j = 0; j < n; j++) {
        scanf("%d", &A[i][j]);
      }
    }

    for (i = 0; i < p; i++) {
      printf("Enter elements for row %d of matrix B:\n", i + 1);
      for (j = 0; j < q; j++) {
        scanf("%d", &B[i][j]);
      }
    }

    multiply(m, n, A, p, q, B, C);

    printf("Matrix A is:\n");
    display(m, n, A);

    printf("Matrix B is:\n");
    display(p, q, B);

    printf("Product of matrices A and B is:\n");
    display(m, q, C);
  }

  return 0;
}

// // Simple iterative matrix multiplication - O(n^3)
//
// three matrices A, B, C. C is the resultant matrix
//
// initialize matrix C with 0
//
// for (int i = 0; i < m; i++) {
//   for (int j = 0; j < q; j++)
//     C[i][j] = 0;
// }
//
// multiply A and B and store in C
//
// for (int i = 0; i < m; i++) {
//   for (int j = 0; j < q; j++) {
//     for (int k = 0; k < n; k++) {
//       C[i][j] += A[i][k] * B[k][j];
//     }
//   }
// }

// just doing the same thing recursively
void multiply(int m, int n, int A[][10], int p, int q, int B[][10],
              int C[][10]) {

  static int i = 0, j = 0, k = 0;

  if (i < m) {
    if (j < q) {
      if (k < n) {
        C[i][j] += A[i][k] * B[k][j];
        k++;
        multiply(m, n, A, p, q, B, C);
      }
      k = 0;
      j++;
      multiply(m, n, A, p, q, B, C);
    }
    j = 0;
    i++;
    multiply(m, n, A, p, q, B, C);
  }
}

void display(int m, int n, int arr[][10]) {

  int i, j;

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}
