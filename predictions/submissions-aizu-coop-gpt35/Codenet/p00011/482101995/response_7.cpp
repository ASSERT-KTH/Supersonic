#include <iostream>

int main() {
  int w;
  std::cin >> w;

  int n;
  std::cin >> n;

  int StartingPoint[w];
  for (int i = 0; i < w; i++) {
    StartingPoint[i] = i + 1;
  }

  for (int i = 0; i < n; i++) {
    int left, right;
    std::cin >> left >> right;
    int temp = StartingPoint[left - 1];
    StartingPoint[left - 1] = StartingPoint[right - 1];
    StartingPoint[right - 1] = temp;
  }

  for (int i = 0; i < w; i++) {
    std::cout << StartingPoint[i] << std::endl;
  }

  return 0;
}