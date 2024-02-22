#include <stdio.h>
#include <unordered_set>

int main() {
  int i, n, q, C = 0;
  int S[100];
  std::unordered_set<int> T;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &S[i]);
  }
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    int temp;
    scanf("%d", &temp);
    T.insert(temp);
  }
  for (i = 0; i < n; i++) {
    if (T.find(S[i]) != T.end()) {
      C++;
    }
  }
  printf("%d\n", C);
  return 0;
}