#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>

int main() {
  int n, k;
  while (std::cin >> n >> k, n) {
    long long prevSum = 0;
    long long maxSum = std::numeric_limits<long long>::min();

    for (int i = 1; i <= n; ++i) {
      long long num;
      std::cin >> num;
      prevSum += num;

      if (i >= k) {
        maxSum = std::max(maxSum, prevSum);
        prevSum -= nums[i - k + 1];
      }
    }

    std::cout << maxSum << std::endl;
  }

  return 0;
}