#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);

  int a = 0, b = 0;
  std::vector<int> H, W;

  while (true) {
    int h, w;
    std::cin >> h >> w;
    if (h == 0 && w == 0)
      break;
    H.push_back(h);
    W.push_back(w);
    ++a;
  }

  while (b < a) {
    for (int i = 0; i < H[b]; ++i) {
      for (int j = 0; j < W[b]; ++j) {
        std::cout << "#";
      }
      std::cout << '\n';
    }
    ++b;
    std::cout << '\n';
  }

  return 0;
}