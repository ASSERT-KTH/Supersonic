#include <stdio.h>
#include <string.h>
int main() {
  int i, m, h, t, a;
  char s[201];
  while (scanf("%s%d", s, &m) == 2 && s[0] != '-') {
    a = strlen(s);
    for (i = t = 0; i < m; ++i) {
      scanf("%d", &h);
      t += h;
    }
    t %= a;
    for (i = t; i < a; ++i) {
      printf("%c", s[i]);
    }
    for (i = 0; i < t; ++i) {
      printf("%c", s[i]);
    }
    printf("\n");
  }
  return 0;
}