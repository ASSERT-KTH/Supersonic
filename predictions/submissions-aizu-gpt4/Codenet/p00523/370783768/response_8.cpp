#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
const int64 INF = 1LL << 58;
int N;
int64 A[200000], sum[200000];
bool Find(const int &pos, const int64 &size) {
  auto hoge = lower_bound(sum + pos + 1, sum + N + pos + 1, sum[pos] + size) - sum;
  if (hoge == N + pos + 1)
    return false;
  auto fuga = lower_bound(sum + hoge + 1, sum + N + pos + 1, sum[hoge] + size) - sum;
  if (fuga == N + pos + 1)
    return false;
  auto foo = lower_bound(sum + fuga + 1, sum + N + pos + 1, sum[fuga] + size) - sum;
  return (foo != N + pos + 1);
}
bool calc(int64 size) {
  for (int pos = 0; pos < N; pos++) {
    if (Find(pos, size))
      return true;
  }
  return false;
}
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", A + i);
    A[N + i] = A[i];
  }
  sum[0] = A[0];
  for (int i = 1; i < 2 * N; i++) {
    sum[i] = sum[i - 1] + A[i];
  }
  int64 low = 0, high = INF;
  while (high - low > 1) {
    int64 mid = (low + high) >> 1;
    if (calc(mid))
      low = mid;
    else
      high = mid;
  }
  printf("%lld\n", low);
}