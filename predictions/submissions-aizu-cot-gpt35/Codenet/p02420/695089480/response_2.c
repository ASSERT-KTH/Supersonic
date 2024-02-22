#include <stdio.h>

int main() {
  char s[201];
  int m, a;

  while (scanf("%s%d", s, &m) == 2) {
    if (s[0] == '-')
      break;

    a = strlen(s);

    int t;
    scanf("%d", &t);

    for (int i = 1; i < m; i++) {
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