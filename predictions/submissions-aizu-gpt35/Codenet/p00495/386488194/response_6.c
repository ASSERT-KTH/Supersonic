#include <stdio.h>
int c[5004], d[5004], m, t, u, i, f = "%d\n";
int main() {
  scanf("%d%*d", c);
  for (i = 1; i <= *c; i++) {
    scanf(f, c + i);
  }
  while (~scanf(f, &t)) {
    for (u = i = 0; i++ <= *c; t = d[i - 1], d[i - 1] = m < u ? m : u) {
      u = t + (t + c[i - 1] == *c);
    }
    m = !printf(f, u);
  }
  return 0;
}