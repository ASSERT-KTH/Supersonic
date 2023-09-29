#include <cstdio>
#include <algorithm>

int main() {
  int n;
  scanf("%d", &n);
  int S[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d", &S[i]);
  }
  std::sort(S, S+n);
  int cnt = 0;
  int q;
  scanf("%d", &q);
  while(q--) {
    int T;
    scanf("%d", &T);
    cnt += std::binary_search(S, S+n, T);
  }
  printf("%d\n", cnt);
  return 0;
}