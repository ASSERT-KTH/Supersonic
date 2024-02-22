#include <iostream>
#include <vector>

struct THorizonalLine {
  int Left;
  int Right;
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

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
    THorizonalLine HorizonalLine;
    char Dummy;
    std::cin >> HorizonalLine.Left >> Dummy >> HorizonalLine.Right;
    std::swap(StartingPoint[HorizonalLine.Left - 1], StartingPoint[HorizonalLine.Right - 1]);
  }

  for (int i = 0; i < w; i++) {
    std::cout << StartingPoint[i] << "\n";
  }

  return 0;
}