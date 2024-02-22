#include <stdio.h>
#include <stdbool.h>

int main() {
  int i, n, q;
  unsigned char C = 0;
  int S[100], T[100];
  bool present[1001] = {false};  // Assuming elements in S and T are in the range [0, 1000]

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &S[i]);
    present[S[i]] = true;
  }

  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &T[i]);
    if (present[T[i]]) {
      C++;
    }
  }

  printf("%hhu\n", C);
  return 0;
}