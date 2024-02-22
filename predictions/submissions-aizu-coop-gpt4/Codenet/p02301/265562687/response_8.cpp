#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <array>

constexpr double EPS = (1e-10);
constexpr double PI = 3.141592653589793238;
constexpr std::array<int, 5> DIRECTIONS = {1, -1, 2, -2, 0};

// Rest of the code ...

int main() {
  int n;
  std::cin >> n;
  Polygon p(n);
  for (int i = 0; i < n; i++)
    std::cin >> p[i];
  printf("%.12f\n", diameter(p));
  return 0;
}