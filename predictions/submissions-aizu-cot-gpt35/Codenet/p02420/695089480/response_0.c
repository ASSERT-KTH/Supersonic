#include <stdio.h>

int main() {
  char s[201];
  int m;

  while (scanf("%s%d", s, &m) == 2 && s[0] != '-') {
    int len = strlen(s);
    int t = 0, i;

    for (i = 0; i < m; i++) {
      int h;
      scanf("%d", &h);
      t += h;
    }

    t %= len;

    for (i = 0; i < len; i++) {
      putchar(s[(t + i) % len]);
    }

    putchar('\n');
  }

  return 0;
}