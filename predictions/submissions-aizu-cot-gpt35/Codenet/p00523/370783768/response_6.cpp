#include <iostream>
#include <vector>

using int64 = long long;
const int64 INF = LLONG_MAX;

int main() {
  int N;
  std::cin >> N;

  std::vector<int> A(N);
  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
  }

  std::vector<int64> sum(2 * N);
  sum[0] = A[0];
  for (int i = 1; i < 2 * N; i++) {
    sum[i] = sum[i - 1] + A[i % N];
  }

  int64 low = 0, high = INF;
  while (high != low) {
    int64 mid = (low + high + 1) >> 1;
    bool found = false;
    for (int pos = 0; pos < N; pos++) {
      int hoge = std::distance(
          sum.begin(), std::lower_bound(sum.begin() + pos + 1, sum.begin() + 2 * N, sum[pos] + mid));
      if (hoge == 2 * N)
        break;
      int fuga = std::distance(
          sum.begin(), std::lower_bound(sum.begin() + hoge + 1, sum.begin() + 2 * N, sum[hoge] + mid));
      if (fuga == 2 * N)
        break;
      int foo = std::distance(
          sum.begin(), std::lower_bound(sum.begin() + fuga + 1, sum.begin() + 2 * N, sum[fuga] + mid));
      if (foo != 2 * N) {
        found = true;
        break;
      }
    }
    if (found)
      low = mid;
    else
      high = mid - 1;
  }

  std::cout << low << std::endl;

  return 0;
}