#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int w;
  std::cin >> w;

  int n;
  std::cin >> n;

  std::vector<int> startingPoint(w);
  for (int i = 0; i < w; i++) {
    startingPoint[i] = i + 1;
  }

  for (int i = 0; i < n; i++) {
    int left, right;
    char dummy;
    std::cin >> left >> dummy >> right;
    std::swap(startingPoint[left - 1], startingPoint[right - 1]);
  }

  std::copy(startingPoint.begin(), startingPoint.end(), std::ostream_iterator<int>(std::cout, "\n"));

  return 0;
}