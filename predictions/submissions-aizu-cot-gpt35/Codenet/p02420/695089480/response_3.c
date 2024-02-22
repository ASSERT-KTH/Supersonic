#include <stdio.h>
#include <string.h>

int main() {
  char s[201];
  int m, a, i, h;

  while (scanf("%s%d", s, &m) == 2 && s[0] != '-') {
    a = strlen(s);

    for (i = 0; i < m; i++) {
      scanf("%d", &h);
    }

    for (i = 0; i < a; i++) {
      printf("%c", s[(i + m) % a]);
    }

    printf("\n");
  }

  return 0;
}