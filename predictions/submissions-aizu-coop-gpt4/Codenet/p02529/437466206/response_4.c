#include <stdio.h>
#include <unordered_map>

int main() {
  int n, q, t, C = 0;
  std::unordered_map<int, bool> S;
  
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &t);
    S[t] = true;
  }
  
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    scanf("%d", &t);
    if (S[t]) {
      ++C;
    }
  }
  
  printf("%d\n", C);
  return 0;
}