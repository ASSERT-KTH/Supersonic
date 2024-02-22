#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> S(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> S[i];
  }
  int cnt = 0;
  int q;
  std::cin >> q;
  for (int i = 0; i < q; ++i) {
    int T;
    std::cin >> T;
    int left = 0;
    int right = n - 1;
    while (left <= right) {
      int mid = (right + left) / 2;
      if (T > S[mid]) {
        left = mid + 1;
      } else if (T < S[mid]) {
        right = mid - 1;
      } else {
        ++cnt;
        break;
      }
    }
  }
  std::cout << cnt << std::endl;
}