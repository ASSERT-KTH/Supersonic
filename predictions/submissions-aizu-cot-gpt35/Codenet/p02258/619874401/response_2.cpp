#include <iostream>
#include <climits>

static const size_t MAX = 200000;

int main() {
  int R[MAX];
  size_t n;
  std::cin >> n;
  std::copy_n(std::istream_iterator<int>(std::cin), n, R);

  int maxv = INT_MIN;
  int minv = R[0];
  for (size_t i = 0; i < n; i++) {
    maxv = std::max(maxv, R[i] - minv);
    minv = std::min(minv, R[i]);
  }

  std::cout << maxv << std::endl;
  return 0;
}