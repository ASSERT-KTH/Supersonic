#include <string.h>
#include <stdio.h>

int main() {
  char s[201];
  int i, m, h, t, a;
  while (scanf("%s%d", s, &m) == 2 && s[0] != '-') {
    a = strlen(s);
    for (i = t = 0; i < m; ++i) {
      scanf("%d", &h);
      t += h;
    }
    for (i = 0; i < a; ++i) {
      printf("%c", s[(t + i) % a]);
    }
    printf("\n");
  }
  return 0;
}