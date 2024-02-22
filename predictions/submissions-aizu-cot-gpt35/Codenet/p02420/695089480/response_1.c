#include <stdio.h>

int main() {
  int m, t;
  char s[201];

  while (scanf("%s%d", s, &m) == 2 && s[0] != '-') {
    int a = 0;
    while (s[a] != '\0')
      a++;

    t = 0;
    for (int i = 0; i < m; i++) {
      int h;
      scanf("%d", &h);
      t += h;
    }

    for (int i = 0; i < a; i++) {
      printf("%c", s[(t + i) % a]);
    }
    printf("\n");
  }

  return 0;
}