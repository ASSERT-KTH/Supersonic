#include <iostream>
#include <vector>
#include <algorithm>

typedef long long int int64;
constexpr int64 INF = 1LL << 58;

bool Find(const std::vector<int64>& sum, int pos, int64 size) {
  auto it = std::lower_bound(sum.begin() + pos + 1, sum.end(), sum[pos] + size);
  if (it == sum.end())
    return false;
  auto it2 = std::lower_bound(it + 1, sum.end(), *it + size);
  if (it2 == sum.end())
    return false;
  auto it3 = std::lower_bound(it2 + 1, sum.end(), *it2 + size);
  return (it3 != sum.end());
}

bool calc(const std::vector<int>& A, const std::vector<int64>& sum, int64 size) {
  int N = A.size();
  for (int pos = 0; pos < N; pos++) {
    if (Find(sum, pos, size))
      return true;
  }
  return false;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  std::cin >> N;

  std::vector<int> A(N * 2);
  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
    A[N + i] = A[i];
  }

  std::vector<int64> sum(N * 2);
  sum[0] = A[0];
  for (int i = 1; i < 2 * N; i++) {
    sum[i] = sum[i - 1] + A[i];
  }

  int64 low = 0, high = INF;
  while (high != low) {
    int64 mid = (low + high + 1) >> 1;
    if (calc(A, sum, mid))
      low = mid;
    else
      high = mid - 1;
  }

  std::cout << low << "\n";

  return 0;
}