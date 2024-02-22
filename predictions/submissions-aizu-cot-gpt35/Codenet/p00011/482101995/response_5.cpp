#include <iostream>
#include <numeric> // for std::iota
#include <algorithm> // for std::swap

struct THorizonalLine {
  int Left;
  int Right;
};

int main() {
  int w;
  std::cin >> w;
  int n;
  std::cin >> n;
  std::vector<int> StartingPoint(w);

  // Step 2: Optimize loop to initialize StartingPoint vector
  std::iota(StartingPoint.begin(), StartingPoint.end(), 1);

  for (int i = 0; i < n; i++) {
    THorizonalLine HorizonalLine;
    char Dummy;
    std::cin >> HorizonalLine.Left >> Dummy >> HorizonalLine.Right;

    // Step 3: Optimize loop to swap elements in StartingPoint vector
    std::swap(StartingPoint[HorizonalLine.Left - 1], StartingPoint[HorizonalLine.Right - 1]);
  }

  for (int i = 0; i < w; i++) {
    // Step 4: Print elements of StartingPoint vector without endl
    std::cout << StartingPoint[i] << '\n';
  }

  return 0;
}