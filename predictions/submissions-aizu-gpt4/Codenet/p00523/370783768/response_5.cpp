#include <algorithm>
#include <cstdio>
#include <iterator>
#include <vector>

typedef long long int64;
const int64 INF = 1LL << 58;

std::vector<int64> sum;

bool Find(const int &pos, const int64 &size, int N) {
  auto first = std::lower_bound(std::next(sum.begin(), pos + 1), std::next(sum.begin(), N + pos + 1), sum[pos] + size);
  if (first == std::next(sum.begin(), N + pos + 1))
    return false;
  auto second = std::lower_bound(std::next(first, 1), std::next(sum.begin(), N + pos + 1), *first + size);
  if (second == std::next(sum.begin(), N + pos + 1))
    return false;
  auto third = std::lower_bound(std::next(second, 1), std::next(sum.begin(), N + pos + 1), *second + size);
  return (third != std::next(sum.begin(), N + pos + 1));
}

bool calc(int64 size, int N) {
  for (int pos = 0; pos < N; pos++) {
    if (Find(pos, size, N))
      return true;
  }
  return false;
}

int main() {
  int N;
  scanf("%d", &N);
  std::vector<int> A(2*N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    A[N + i] = A[i];
  }
  sum.resize(2*N);
  sum[0] = A[0];
  for (int i = 1; i < 2 * N; i++) {
    sum[i] = sum[i - 1] + A[i];
  }
  int64 low = 0, high = INF;
  while (high != low) {
    int64 mid = (low + high + 1) >> 1;
    if (calc(mid, N))
      low = mid;
    else
      high = mid - 1;
  }
  printf("%lld\n", low);
}