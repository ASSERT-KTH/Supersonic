#include <iostream>
#include <vector>
#include <string>

int main() {
  std::vector<std::pair<int, int>> sizes;
  int height, width;

  while (std::cin >> height >> width && (height != 0 && width != 0)) {
    sizes.push_back({height, width});
  }

  for (const auto& size : sizes) {
    std::string line(size.second, '#');

    for (int i = 0; i < size.first; i++) {
      std::cout << line << "\n";
    }
    std::cout << "\n";
  }
  return 0;
}