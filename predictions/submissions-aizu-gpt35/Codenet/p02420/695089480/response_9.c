#include <stdio.h>
#include <string.h>

int main() {
  int i, m, a, t, h;
  char s[201];
  while (scanf("%s %d", s, &m) == 2 && s[0] != '-') {
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