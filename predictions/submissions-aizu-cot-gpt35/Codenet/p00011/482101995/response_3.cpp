#include <iostream>
#include <vector>

struct THorizontalLine {
  int Left;
  int Right;
};

int main() {
  int w;
  std::cin >> w;
  int n;
  std::cin >> n;

  std::vector<int> StartingPoint;
  StartingPoint.reserve(w);
  for (int i = 0; i < w; i++) {
    StartingPoint.push_back(i + 1);
  }

  for (int i = 0; i < n; i++) {
    THorizontalLine HorizonalLine;
    char Dummy;
    std::cin >> HorizonalLine.Left >> Dummy >> HorizonalLine.Right;
    std::swap(StartingPoint[HorizonalLine.Left - 1],
              StartingPoint[HorizonalLine.Right - 1]);
  }

  for (const auto& point : StartingPoint) {
    std::cout << point << '\n';
  }

  return 0;
}