#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

struct THorizonalLine {
  int Left;
  int Right;
};

int main() {
  std::ios_base::sync_with_stdio(false);

  int w;
  std::cin >> w;

  int n;
  std::cin >> n;

  std::array<int, 100000> StartingPoint;
  StartingPoint.fill(0);
  std::vector<int> leftPoints(n);
  std::vector<int> rightPoints(n);

  for (int i = 0; i < n; i++) {
    std::cin >> leftPoints[i];
    char Dummy;
    std::cin >> Dummy >> rightPoints[i];
  }

  for (int i = 0; i < n; i++) {
    std::swap(StartingPoint[leftPoints[i] - 1], StartingPoint[rightPoints[i] - 1]);
  }

  for (int i = 0; i < w; i++) {
    std::cout << StartingPoint[i] << std::endl;
  }

  return 0;
}