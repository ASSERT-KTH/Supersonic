#include <iostream>
#include <vector>

int check(const std::vector<int>& N, int k, int w) {
  int i = 0;
  for (int j = 0; j < k; ++j) {
    int s = 0;
    while (s + N[i] <= w) {
      s += N[i];
      ++i;
      if (i == N.size())
        return N.size();
    }
  }
  return i;
}

int main() {
  int MAX_W = 1000000000;
  int n, k;
  std::cin >> n >> k;
  std::vector<int> N(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> N[i];
  }
  int left = 0;
  int right = *std::max_element(N.begin(), N.end()); // Use max element as the upper bound
  while (left < right) {
    int mid = left + (right - left) / 2; // Use integer division
    int result = check(N, k, mid);
    if (result == n) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  std::cout << right << std::endl;
  return 0;
}