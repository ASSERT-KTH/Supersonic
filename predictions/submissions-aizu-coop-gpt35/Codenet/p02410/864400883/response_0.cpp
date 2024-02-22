#include <iostream>

int main() {
  int n, m;
  int x, y, *a, *b;
  int c = 0;

  std::cin >> n >> m;

  // Allocate memory for matrix a
  a = new int[n * m];

  // Read values of matrix a and b
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> x;
      a[i * m + j] = x;
    }
    std::cin >> y;
    b[i] = y;
  }

  // Perform matrix multiplication and print the result
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      c += a[i * m + j] * b[j];
    }
    std::cout << c << std::endl;
    c = 0;
  }

  // Deallocate memory for matrix a
  delete[] a;

  return 0;
}