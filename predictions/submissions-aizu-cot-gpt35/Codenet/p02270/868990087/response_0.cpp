#include <cstdio>
#include <iostream>
#include <vector>

int check(const std::vector<int>& N, int n, int k, int w) {
  int i = 0;
  for (int j = 0; j < k; ++j) {
    int s = 0;
    while (s + N[i] <= w) {
      s += N[i];
      ++i;
      if (i == n)
        return n;
    }
  }
  return i;
}

int main() {
  long long int MAX_W = 1000000000;
  int n, k;
  std::cin >> n >> k;
  std::vector<int> N(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> N[i];
  }
  int left = 0;
  int right = MAX_W;
  while (left < right) {
    int mid = (left + right) / 2;
    if (check(N, n, k, mid) == n) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  std::cout << right << std::endl;
  return 0;
}