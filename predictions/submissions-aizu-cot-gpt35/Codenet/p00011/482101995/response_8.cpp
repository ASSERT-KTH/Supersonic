#include <iostream>
#include <vector>

struct THorizonalLine {
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
  for (int i = 0; i < w; ++i) {
    StartingPoint.emplace_back(i + 1);
  }

  for (int i = 0; i < n; ++i) {
    THorizonalLine HorizonalLine;
    char Dummy;
    std::cin >> HorizonalLine.Left >> Dummy >> HorizonalLine.Right;

    int temp = StartingPoint[HorizonalLine.Left - 1];
    StartingPoint[HorizonalLine.Left - 1] = StartingPoint[HorizonalLine.Right - 1];
    StartingPoint[HorizonalLine.Right - 1] = temp;
  }

  for (int i = 0; i < w; ++i) {
    std::cout << StartingPoint[i] << std::endl;
  }

  return 0;
}