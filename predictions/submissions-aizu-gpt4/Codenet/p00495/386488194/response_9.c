#include <stdio.h>
#define MAX 5004

int c[MAX], d[MAX], m, t, u, i;
char f[] = "%d\n";

int main() {
  int x;
  scanf("%d%*d", c);
  for (i = 1; i <= *c; ++i) {
    scanf(f, c + i);
  }
  while(~scanf(f, &x)) {
    u = i = t = 0;
    for(; i <= *c; ++i) {
      t = d[i];
      u = x - c[i] ? u : t + 1;
      d[i] = m < u ? (m = u) : u;
    }
  }
  printf(f, m);
  return 0;
}