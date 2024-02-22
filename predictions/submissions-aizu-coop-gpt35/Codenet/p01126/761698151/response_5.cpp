#include <iostream>
#include <unordered_map>

int main() {
  int n, m, a;
  while (true) {
    std::cin >> n >> m >> a;
    if (n == 0 && m == 0 && a == 0) {
      break;
    }

    std::unordered_map<int, int> amida;
    for (int i = 0; i < m; i++) {
      int h = 0, p = 0, q = 0;
      std::cin >> h >> p >> q;
      amida[h] = p;
    }

    for (int j = 1000; j > 0; j--) {
      int currentBar = amida[j];
      if (currentBar == a)
        a++;
      else if (currentBar == a - 1)
        a--;
    }

    std::cout << a << std::endl;
  }
  return 0;
}