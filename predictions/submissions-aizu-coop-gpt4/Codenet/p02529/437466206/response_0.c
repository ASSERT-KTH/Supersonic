#include <stdio.h>
#include <unordered_set>

int main() {
  int i, n, q, t, C = 0;
  std::unordered_set<int> S;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &t);
    S.insert(t);
  }
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &t);
    if (S.find(t) != S.end()) {
      C++;
    }
  }
  printf("%d\n", C);
  return 0;
}