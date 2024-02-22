#include <iostream>
#include <vector>

int main() {
  std::vector<std::pair<int, int>> rectangles;

  while (true) {
    int h, w;
    std::cin >> h >> w;

    if (h == 0 && w == 0)
      break;

    rectangles.push_back(std::make_pair(h, w));
  }

  for (const auto& rect : rectangles) {
    int h = rect.first;
    int w = rect.second;

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        std::cout << "#";
      }
      std::cout << "\n";
    }

    std::cout << "\n";
  }

  return 0;
}