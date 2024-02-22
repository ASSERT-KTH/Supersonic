#include <stdio.h>

int main() {
  int c[5004], m, t, u, i, x;
  char f[] = "%d\n";

  scanf("%d%*d", c);

  for (i = 0; i < *c; i++) {
    scanf(f, c + i + 1);
  }

  for (m = i = 0; ~scanf(f, &x);) {
    for (u = t = 0; i++ < *c; t = m < u ? (m = u) : u) {
      u = x == c[i] ? t + 1 : u;
    }
  }

  printf(f, m);

  return 0;
}