#include <iostream>

int main() {
  const int n, m;
  std::cin >> n >> m;

  int** a = new int*[n];
  for (int i = 0; i < n; i++) {
    a[i] = new int[m];
    for (int j = 0; j < m; j++) {
      std::cin >> a[i][j];
    }
  }

  int* b = new int[m];
  for (int j = 0; j < m; j++) {
    std::cin >> b[j];
  }

  for (int i = 0; i < n; i++) {
    int c = 0;
    for (int j = 0; j < m; j++) {
      c += a[i][j] * b[j];
    }
    std::cout << c << std::endl;
  }

  for (int i = 0; i < n; i++) {
    delete[] a[i];
  }
  delete[] a;
  delete[] b;

  return 0;
}