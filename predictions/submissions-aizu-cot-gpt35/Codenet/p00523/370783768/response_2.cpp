#include <stdio.h>

const long long INF = 1e18;

int N, A[200000];
long long sum[200000];

bool Find(const int &pos, const long long &size) {
  int hoge = pos + 1;
  while (hoge < N + pos + 1 && sum[hoge] < sum[pos] + size) {
    hoge++;
  }
  if (hoge == N + pos + 1) {
    return false;
  }
  
  int fuga = hoge + 1;
  while (fuga < N + pos + 1 && sum[fuga] < sum[hoge] + size) {
    fuga++;
  }
  if (fuga == N + pos + 1) {
    return false;
  }
  
  int foo = fuga + 1;
  while (foo < N + pos + 1 && sum[foo] < sum[fuga] + size) {
    foo++;
  }
  
  return foo != N + pos + 1;
}

bool calc(long long size) {
  for (int pos = 0; pos < N; pos++) {
    if (Find(pos, size)) {
      return true;
    }
  }
  return false;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    A[N + i] = A[i];
  }
  
  sum[0] = A[0];
  for (int i = 1; i < 2 * N; i++) {
    sum[i] = sum[i - 1] + A[i];
  }
  
  long long low = 0, high = INF;
  while (high != low) {
    long long mid = (low + high + 1) >> 1;
    if (calc(mid)) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }
  
  printf("%lld\n", low);
}