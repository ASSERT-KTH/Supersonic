#include <cstdio>
#include <algorithm>
const int MAXN = 1e6 + 5;
int n, A[MAXN], cnt[MAXN];
int main() {
  scanf("%d", &n);
  for (int i = 0, x; i < n; ++i) {
    scanf("%d", &x);
    ++cnt[x + 1];
  }
  for (int i = 1; i < MAXN; ++i)
    cnt[i] += cnt[i - 1];
  for (int i = 0; i < n; ++i)
    A[--cnt[A[i] + 1]] = A[i];
  for (int i = 0; i < n; ++i)
    printf("%d ", A[i]);
}