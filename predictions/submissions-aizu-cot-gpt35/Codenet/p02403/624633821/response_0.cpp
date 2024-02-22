#include <iostream>
#include <vector>

int main() {
  std::vector<int> H, W;
  int h, w;
  
  while (std::cin >> h >> w && (h != 0 || w != 0)) {
    H.push_back(h);
    W.push_back(w);
  }
  
  for (size_t i = 0; i < H.size(); i++) {
    for (int j = 0; j < H[i]; j++) {
      for (int k = 0; k < W[i]; k++) {
        std::cout << "#";
      }
      std::cout << "\n";
    }
    std::cout << "\n";
  }
  
  return 0;
}