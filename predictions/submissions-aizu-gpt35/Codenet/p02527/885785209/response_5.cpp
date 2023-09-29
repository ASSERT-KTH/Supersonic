#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int a[MAXN];
template <typename T> void quicksort(T *l, T *r) {
  if (r - l < 2) return;
  T *piv = l + rand() % (r - l);
  piv = partition(l, r, [&](T &x) { return x < *piv; });
  if (piv != l) quicksort(l, piv);
  if (piv != r - 1) quicksort(piv + 1, r);
}

int main() {
  srand(time(0));
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  quicksort(a, a + n);
  for (int i = 0; i < n; i++) printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
  return 0;
}