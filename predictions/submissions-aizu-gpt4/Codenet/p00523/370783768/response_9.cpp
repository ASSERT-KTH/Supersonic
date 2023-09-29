#include <bits/stdc++.h>
#define MAXN 200000
#define INF (1LL << 58)
using namespace std;
typedef long long int64;
int N, A[MAXN * 2];
int64 sum[MAXN * 2];

bool calc(int64 size) {
  int hoge, fuga, foo;
  for (int pos = 0; pos < N; pos++) {
    hoge = lower_bound(sum + pos + 1, sum + N + pos + 1, sum[pos] + size) - sum;
    if (hoge == N + pos + 1)
      continue;
    fuga = lower_bound(sum + hoge + 1, sum + N + pos + 1, sum[hoge] + size) - sum;
    if (fuga == N + pos + 1)
      continue;
    foo = lower_bound(sum + fuga + 1, sum + N + pos + 1, sum[fuga] + size) - sum;
    if (foo != N + pos + 1)
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
  partial_sum(A, A + 2 * N, sum);
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