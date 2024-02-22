#include <iostream>
#include <vector>

int main() {
  int n, m, a;
  while (true) {
    std::cin >> n >> m >> a;
    if (n == 0 && m == 0 && a == 0) {
      break;
    }
    std::vector<std::vector<int>> amida(n + 1, std::vector<int>(1001, 0));
    for (int i = 0; i < m; i++) {
      int h = 0, p = 0, q = 0;
      std::cin >> h >> p >> q;
      amida[p][h] = 1;
    }
    for (int j = 1; j <= 1000; j++) {
      if (amida[a][j] == 1) {
        a++;
      } else if (amida[a - 1][j] == 1) {
        a--;
      }
    }
    std::cout << a << std::endl;
  }
  return 0;
}