#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n, m;
  std::vector<int> o;
  std::vector<std::string> b;
  std::string l;
  int ans;

  while (std::cin >> n >> m && (n != 0 || m != 0)) {
    ans = 0;
    o.resize(n);
    b.resize(n);

    for (int i = 0; i < n; i++) {
      std::cin >> b[i] >> o[i];
    }

    for (int i = 0; i < m; i++) {
      std::cin >> l;

      for (int j = 0; j < n; j++) {
        if (std::equal(b[j].begin(), b[j].end(), l.begin(), l.begin() + 8)) {
          ans += o[j];
          break;
        }
      }
    }

    std::cout << ans << std::endl;
  }

  return 0;
}