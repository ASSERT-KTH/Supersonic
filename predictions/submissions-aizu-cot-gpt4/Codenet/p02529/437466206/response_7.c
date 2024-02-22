#include <stdio.h>
#include <algorithm>

int main() {
  int i, n, q, t, C = 0, S[100];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &S[i]);
  }
  std::sort(S, S + n); // sort the array S[]
  scanf("%d", &q);
  while(q--) {
    scanf("%d", &t);
    if (std::binary_search(S, S + n, t)) { // binary search for t in S[]
      C++;
    }
  }
  printf("%d\n", C);
  return 0;
}