#include <iostream>
#include <vector>

int main() {
  int a = 0;
  std::vector<int> H, W;

  while (1) {
    int h, w;
    std::cin >> h >> w;
    if (h == 0 && w == 0)
      break;
    H.push_back(h);
    W.push_back(w);
    a++;
  }

  for (int i = 0; i < a; i++) {
    for (int j = 0; j < H[i]; j++) {
      for (int k = 0; k < W[i]; k++) {
        std::cout << "#";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }

  return 0;
}