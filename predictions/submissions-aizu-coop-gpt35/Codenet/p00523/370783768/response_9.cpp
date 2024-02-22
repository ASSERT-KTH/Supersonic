#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
const int64 INF = 1LL << 58;
int N, A[200000];

bool Find(const int &pos, const int64 &size) {
  int hoge = distance(
      sum, lower_bound(sum + pos + 1, sum + N + pos + 1, sum[pos] + size));
  if (hoge == N + pos + 1)
    return false;
  int fuga = distance(
      sum, lower_bound(sum + hoge + 1, sum + N + pos + 1, sum[hoge] + size));
  if (fuga == N + pos + 1)
    return false;
  int foo = distance(
      sum, lower_bound(sum + fuga + 1, sum + N + pos + 1, sum[fuga] + size));
  return (foo != N + pos + 1);
}

bool calc(int64 size) {
  for (int pos = 0; pos < N - 1; pos += 2) {
    if (Find(pos, size) || Find(pos + 1, size))
      return true;
  }
  if (Find(N - 1, size))
    return true;
  return false;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", A + i);
    A[N + i] = A[i];
  }

  int64 prefixSum = A[0];
  int64 low = 0, high = 1;
  while (high < INF && !calc(high))
    high *= 2;

  while (high != low) {
    int64 mid = (low + high + 1) >> 1;
    if (calc(mid))
      low = mid;
    else
      high = mid - 1;
  }
  printf("%lld\n", low);
}