#include <iostream>

int main() {
  int n, m;
  int a[100][100], b[100];
  int c = 0;

  std::cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    int x;
    for (int j = 0; j < m; ++j) {
      std::cin >> x;
      a[i][j] = x;
    }
  }

  for (int j = 0; j < m; ++j) {
    std::cin >> b[j];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      c += a[i][j] * b[j];
    }
    std::cout << c << std::endl;
    c = 0;
  }
  
  return 0;
}