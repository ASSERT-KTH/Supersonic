#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
const int64 INF = 1LL << 58;
int N, A[200000];
int64 sum[200001];
bool Find(const int &pos, const int64 &size) {
  int hoge = lower_bound(sum + pos + 1, sum + N + pos + 1, sum[pos] + size) - sum;
  if (hoge == N + pos + 1)
    return false;
  int fuga = lower_bound(sum + hoge + 1, sum + N + pos + 1, sum[hoge] + size) - sum;
  if (fuga == N + pos + 1)
    return false;
  int foo = lower_bound(sum + fuga + 1, sum + N + pos + 1, sum[fuga] + size) - sum;
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
    scanf("%d", A + i);
    A[N + i] = A[i];
  }
  sum[0] = 0;
  for (int i = 1; i <= 2 * N; i++) {
    sum[i] = sum[i - 1] + A[i-1];
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