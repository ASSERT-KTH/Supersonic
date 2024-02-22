#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  int n, m;
  int a[100][100], b[100];
  int c = 0;
  std::cin >> n >> m;
  
  for (int j = 0; j < m; ++j) {
    std::cin >> b[j];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> a[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    c = 0;
    for (int j = 0; j < m; ++j) {
      c += a[i][j] * b[j];
    }
    std::cout << c << '\n';
  }

  return 0;
}