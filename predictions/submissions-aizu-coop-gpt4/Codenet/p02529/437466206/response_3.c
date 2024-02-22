#include <stdio.h>
#include <unordered_set>

int main() {
  int i, n, q, t, C = 0, S[100], T[100];
  std::unordered_set<int> S_set;
  
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &S[i]);
    S_set.insert(S[i]);  // Insert the elements of S into the hash set
  }
  
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &T[i]);
  }

  for (i = 0; i < q; i++) {
    if (S_set.count(T[i])) {  // Check if T[i] is in the hash set
      C++;
    }
  }
  printf("%d\n", C);
  return 0;
}