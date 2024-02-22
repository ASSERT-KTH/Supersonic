#include <iostream>

int main() {
  int n, m;
  int x, y;
  int** a;
  int* b;
  int c = 0;

  std::cin >> n >> m;

  // Allocate memory for matrix a
  a = new int*[n];
  for (int i = 0; i < n; i++) {
    a[i] = new int[m];
  }

  // Allocate memory for vector b
  b = new int[m];

  // Read matrix a values
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> x;
      a[i][j] = x;
    }
  }

  // Read vector b values
  for (int j = 0; j < m; j++) {
    std::cin >> y;
    b[j] = y;
  }

  // Compute matrix-vector product
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      c += a[i][j] * b[j];
    }
    std::cout << c << std::endl;
    c = 0;
  }

  // Free memory for matrix a
  for (int i = 0; i < n; i++) {
    delete[] a[i];
  }
  delete[] a;

  // Free memory for vector b
  delete[] b;

  return 0;
}