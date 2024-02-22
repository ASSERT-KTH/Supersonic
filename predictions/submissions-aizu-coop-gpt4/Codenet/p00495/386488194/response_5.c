#include <stdio.h>
#include <stdlib.h>

int main() {
  int *c, *d, t, u, i, f = "%d\n";
  int x;
  c = (int *)malloc(5004 * sizeof(int));
  d = (int *)malloc(5004 * sizeof(int));

  for (scanf("%d%*d", c); i < *c; scanf(f, ++i + c))
    ;

  for (; ~scanf(f, &x);) {
    int m = 0;
    for (u = i = t = 0; i++ < *c; t = d[i], d[i] = m < u ? m = u : u)
      u = x - c[i] ? u : t + 1;
    m = !printf(f, m);
  }

  free(c);
  free(d);

  return 0;
}