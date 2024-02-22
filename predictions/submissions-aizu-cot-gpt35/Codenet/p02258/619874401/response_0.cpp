#include <iostream>
static const int MAX = 200000;
int main() {
  int R[MAX], n;
  std::cin >> n;
  for (int i = 0; i < n; i++)
    std::cin >> R[i];
  int maxv = INT_MIN;
  int minv = INT_MAX;
  for (int i = 0; i < n; i++) {
    maxv = std::max(maxv, R[i] - minv);
    minv = std::min(minv, R[i]);
  }
  std::cout << maxv << std::endl;
  return 0;
}