#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> R(n);
  for (int i = 0; i < n; ++i)
    std::cin >> R[i];
  int maxv = R[1] - R[0];
  int minv = R[0];
  for (int i = 1; i < n; ++i) {
    maxv = std::max(maxv, R[i] - minv);
    minv = std::min(minv, R[i]);
  }
  std::cout << maxv << '\n';
  return 0;
}