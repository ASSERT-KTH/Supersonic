#include <stdio.h>
#include <algorithm>

int c[5004], d[5004], m, t, u, i, n;
char f[] = "%d\n";

int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; ++i)
    scanf("%d", c + i);

  while (scanf(f, &u) != EOF) {
    std::fill_n(d, n + 1, 0);
    m = t = 0;
    for (i = 1; i <= n; ++i) {
      d[i] = std::max(d[i - 1], u == c[i] ? t + 1 : 0);
      t = d[i - 1];
      m = std::max(m, d[i]);
    }
  }
  printf(f, m);
  return 0;
}