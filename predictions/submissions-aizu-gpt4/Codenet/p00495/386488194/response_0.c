#include <stdio.h>
#define SIZE 5004

int c[SIZE], d[SIZE], m, t, u, i;
char f[] = "%d\n";

int main() {
  scanf("%d%*d", c);
  for (i = 1; i < c[0]; ++i)
    scanf(f, c + i);
  while (~scanf(f, &m)) {
    u = i = t = m = 0;
    for (; i++ < c[0]; t = d[i], d[i] = m < u ? m = u : u)
      u = m - c[i] ? u : t + 1;
  }
  printf(f, m);
  return 0;
}