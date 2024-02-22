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
    int right = n - 1;  // Update the right boundary to n - 1
    while (left <= right) {  // Change the termination condition to <=
      int mid = left + (right - left) / 2;  // Compute mid inside the loop
      if (T < S[mid]) {
        right = mid - 1;
      } else if (T > S[mid]) {
        left = mid + 1;
      } else {
        ++cnt;
        break;
      }
    }
  }
  std::cout << cnt << std::endl;
  return 0;
}