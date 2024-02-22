#include <stdio.h>
#include <unordered_set>

int main() {
  int i, k, n, q, t, C = 0;
  std::unordered_set<int> S_set;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &t);
    S_set.insert(t);
  }

  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &t);
    if (S_set.find(t) != S_set.end()) {
      C++;
    }
  }

  printf("%d\n", C);
  return 0;
}