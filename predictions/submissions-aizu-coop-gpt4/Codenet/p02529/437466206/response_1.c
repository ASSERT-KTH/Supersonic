#include <stdio.h>
#include <unordered_set>

int main() {
  int i, n, q, C = 0, S[100], T[100];
  scanf("%d", &n);
  std::unordered_set<int> S_set;
  
  for (i = 0; i < n; i++) {
    scanf("%d", &S[i]);
    S_set.insert(S[i]); // Insert elements into set for efficient lookup
  }
  
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &T[i]);
    if (S_set.find(T[i]) != S_set.end()) { // Check if T[i] is in S_set
      C++;
    }
  }
  
  printf("%d\n", C);
  return 0;
}