#include <iostream>

int main() {
  int H, W;
  std::cin >> H >> W;
  
  while (H != 0 && W != 0) {
    for (int i = 1; i <= H; i++) {
      for (int j = 1; j <= W/2; j++) {
        if ((i + j) % 2 == 0) {
          std::cout << '.';
        } else {
          std::cout << '#';
        }
        
        std::cout << '.';
      }
      
      std::cout << '\n';
    }
    
    std::cout << '\n';
    std::cin >> H >> W;
  }
  
  return 0;
}