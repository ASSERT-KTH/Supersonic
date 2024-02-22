#include <stdio.h>
#include <unordered_set>

int main() {
  int n, q, i, cnt = 0;
  std::unordered_set<int> S;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    int s;
    scanf("%d", &s);
    S.insert(s);
  }

  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    int t;
    scanf("%d", &t);
    if (S.find(t) != S.end()) {
      cnt++;
    }
  }

  printf("%d\n", cnt);
  return 0;
}