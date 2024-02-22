#include <iostream>
#include <string>
int main() {
  int H, W;
  std::cin >> H >> W;
  while (H != 0 && W != 0) {
    std::string pattern;
    for (int i = 1; i <= H; i++) {
      for (int j = 1; j <= W; j++) {
        pattern += ".#"[(i ^ j) & 1];
      }
      pattern += '\n';
    }
    std::cout << pattern << std::endl;
    std::cin >> H >> W;
  }
  return 0;
}