#include <iostream>
#include <vector>

int main() {
  std::vector<int> H, W;
  int h, w;

  while (true) {
    std::cin >> h >> w;
    if (h == 0 && w == 0)
      break;
    H.push_back(h);
    W.push_back(w);
  }

  for (int i = 0; i < H.size(); ++i) {
    int height = H[i];
    int width = W[i];

    for (int j = 0; j < height; ++j) {
      for (int k = 0; k < width; ++k) {
        std::cout << "#";
      }
      std::cout << std::endl;
    }

    std::cout << std::endl;
  }

  return 0;
}