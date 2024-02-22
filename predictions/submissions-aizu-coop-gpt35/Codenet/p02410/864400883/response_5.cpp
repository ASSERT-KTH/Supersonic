#include <iostream>
#include <vector>

int main() {
  int n, m;
  int x, y;
  std::cin >> n >> m;

  // Use std::vector instead of raw arrays
  std::vector<std::vector<int>> a(n, std::vector<int>(m));
  std::vector<int> b(m);

  // Read values into temporary variable and assign to a
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> x;
      a[i][j] = x;
    }
  }

  // Read values directly into b
  for (int j = 0; j < m; j++) {
    std::cin >> b[j];
  }

  // Optimized inner loop with loop unrolling
  for (int i = 0; i < n; i++) {
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
    for (int j = 0; j < m; j += 4) {
      c1 += a[i][j] * b[j];
      c2 += a[i][j + 1] * b[j + 1];
      c3 += a[i][j + 2] * b[j + 2];
      c4 += a[i][j + 3] * b[j + 3];
    }
    int c = c1 + c2 + c3 + c4;
    std::cout << c << '\n';
  }

  return 0;
}