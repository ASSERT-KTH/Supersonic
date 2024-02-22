#include <iostream>
#include <vector>

int main() {
  int a = 0;
  std::vector<int> H, W;
  
  while (true) {
    int h, w;
    std::cin >> h >> w;
    
    if (h == 0 && w == 0)
      break;
    
    H.push_back(h);
    W.push_back(w);
    a++;
  }
  
  for (int b = 0; b < a; b++) {
    for (int i = 0; i < H[b]; i++) {
      for (int j = 0; j < W[b]; j++) {
        std::cout << '#';
      }
      std::cout << '\n';
    }
    std::cout << '\n';
  }
  
  return 0;
}