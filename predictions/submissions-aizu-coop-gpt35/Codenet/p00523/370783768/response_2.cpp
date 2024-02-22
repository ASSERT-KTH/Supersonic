#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
const int64 INF = 1LL << 58;
int N, A[200000];
int64 prefixSum[400000];
bool result[200000];

bool Find(const int &pos, const int64 &size) {
  int hoge = distance(
      prefixSum, lower_bound(prefixSum + pos + 1, prefixSum + N + pos + 1, prefixSum[pos] + size));
  if (hoge == N + pos + 1)
    return false;
  int fuga = distance(
      prefixSum, lower_bound(prefixSum + hoge + 1, prefixSum + N + pos + 1, prefixSum[hoge] + size));
  if (fuga == N + pos + 1)
    return false;
  int foo = distance(
      prefixSum, lower_bound(prefixSum + fuga + 1, prefixSum + N + pos + 1, prefixSum[fuga] + size));
  return (foo != N + pos + 1);
}

bool calc(int64 size) {
  int windowSize = N - 1;
  int windowStart = 0;
  int windowEnd = windowSize;
  for (int i = 0; i < windowSize; i++) {
    result[i] = Find(i, size);
  }
  while (windowEnd < 2 * N) {
    result[windowEnd] = Find(windowEnd, size);
    if (result[windowStart]) {
      return true;
    }
    windowStart++;
    windowEnd++;
  }
  return false;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", A + i);
    A[N + i] = A[i];
  }
  prefixSum[0] = A[0];
  for (int i = 1; i < 2 * N; i++) {
    prefixSum[i] = prefixSum[i - 1] + A[i];
  }
  int64 low = 0, high = INF;
  while (high != low) {
    int64 mid = (low + high + 1) >> 1;
    if (calc(mid))
      low = mid;
    else
      high = mid - 1;
  }
  printf("%lld\n", low);
}