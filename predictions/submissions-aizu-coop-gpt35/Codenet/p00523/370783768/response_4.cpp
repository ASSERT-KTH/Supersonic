#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
const int64 INF = 1LL << 58;
int N, A[200000];
int sum[200000];
bool Find(const int &pos, const int &size) {
  int hoge = pos + 1;
  while (hoge < N + pos + 1 && sum[hoge] < sum[pos] + size)
    hoge++;
  if (hoge == N + pos + 1)
    return false;
  int fuga = hoge + 1;
  while (fuga < N + pos + 1 && sum[fuga] < sum[hoge] + size)
    fuga++;
  if (fuga == N + pos + 1)
    return false;
  int foo = fuga + 1;
  while (foo < N + pos + 1 && sum[foo] < sum[fuga] + size)
    foo++;
  return (foo != N + pos + 1);
}
bool calc(int size) {
  for (int pos = 0; pos < 2 * N; pos++) {
    if (Find(pos, size))
      return true;
  }
  return false;
}
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", A + i);
    sum[i] = i;
  }
  int64 low = 0, high = INF;
  while (high != low) {
    int64 mid1 = low + (high - low) / 3;
    int64 mid2 = high - (high - low) / 3;
    if (calc(mid1) || calc(mid2))
      low = mid1;
    else
      high = mid2 - 1;
  }
  printf("%lld\n", low);
}