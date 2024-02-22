#include <stdio.h>

int main() {
  char s[201];
  int m, len, i, h, sum;

  while (scanf("%s %d", s, &m) == 2 && s[0] != '-') {
    len = strlen(s);
    sum = 0;

    for (i = 0; i < m; i++) {
      scanf("%d", &h);
      sum += h;
    }

    for (i = 0; i < len; i++) {
      putchar(s[(sum + i) % len]);
    }

    putchar('\n');
  }

  return 0;
}