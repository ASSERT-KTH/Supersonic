#include <stdio.h>
#include <unordered_set>

int main() {
  int i, n, q, C = 0;
  std::unordered_set<int> S, T;
  
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    S.insert(num);
  }
  
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    int num;
    scanf("%d", &num);
    T.insert(num);
  }
  
  for (auto num : T) {
    if (S.count(num)) {
      C++;
    }
  }
  
  printf("%d\n", C);
  return 0;
}