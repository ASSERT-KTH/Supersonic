#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> R(n);
  for (int i = 0; i < n; i++)
    std::cin >> R[i];

  int maxv = std::numeric_limits<int>::min();
  int minv = R[0];

  for (int i = 1; i < n; i++) {
    maxv = std::max(maxv, R[i] - minv);
    minv = std::min(minv, R[i]);
  }

  std::cout << maxv;

  return 0;
}