#include <stdio.h>
#define MAXN 5004

int c[MAXN], d[MAXN];
int m, t, u, i, f;

int main() {
  scanf("%d", &f);
  for (i = 0; i < f; i++) scanf("%d", &c[i]);
  for (;;) {
    int x;
    if (scanf("%d", &x) < 1) break;
    for (u = i = t = 0; i < f; i++) {
      int temp = d[i];
      d[i] = m < u ? m = u : u;
      u = x - c[i] ? u : temp + 1;
    }
  }
  printf("%d\n", m);
  return 0;
}