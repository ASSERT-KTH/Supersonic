#include <iostream>
#include <array>

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
  
  std::array<int, w> StartingPoint;
  StartingPoint.reserve(w);
  
  for (int i = 0; i < w; i++) {
    StartingPoint[i] = i + 1;
  }
  
  for (int i = 0; i < n; i++) {
    THorizonalLine HorizonalLine;
    char Dummy;
    std::cin >> HorizonalLine.Left >> Dummy >> HorizonalLine.Right;
    
    StartingPoint[HorizonalLine.Left - 1] = StartingPoint[HorizonalLine.Right - 1];
    StartingPoint[HorizonalLine.Right - 1] = StartingPoint[HorizonalLine.Left - 1];
  }
  
  for (int i = 0; i < w; i++) {
    std::cout << StartingPoint[i] << '\n';
  }
  
  return 0;
}