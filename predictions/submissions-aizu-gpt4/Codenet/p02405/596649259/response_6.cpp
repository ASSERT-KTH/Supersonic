#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  
  int H, W;
  while (std::cin >> H >> W && H != 0 && W != 0) {
    std::string row[2];
    row[0] = std::string(W/2 + W%2, '.');
    row[1] = std::string(W/2, '#');
    row[0] += std::string(W/2, '#');
    row[1] += std::string(W/2 + W%2, '.');
    for (int i = 1; i <= H; i++) {
      std::cout << row[i%2] << '\n';
    }
    std::cout << '\n';
  }
  return 0;
}