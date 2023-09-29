#include <iostream>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n, std::vector<int>(m));
  std::vector<int> b(m);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> a[i][j];
    }
  }
  for (int j = 0; j < m; j++) {
    std::cin >> b[j];
  }
  for (int i = 0; i < n; i++) {
    int c = 0;
    for (int j = 0; j < m; j++) {
      c += a[i][j] * b[j];
    }
    std::cout << c << '\n';
  }
  return 0;
}