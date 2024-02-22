#include <stdio.h>
#include <stdbool.h>
#include <unordered_set>

int main() {
  int i, n, q, C = 0;
  std::unordered_set<int> S;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    int value;
    scanf("%d", &value);
    S.insert(value);
  }
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    int value;
    scanf("%d", &value);
    if (S.find(value) != S.end()) {
      C++;
    }
  }
  printf("%d\n", C);
  return 0;
}