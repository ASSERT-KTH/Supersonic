#include <stdio.h>
#include <string.h>

int main() {
  char s[201];
  int m, len, i, h, t;

  while (fgets(s, sizeof(s), stdin)) {
    if (s[0] == '-')
      break;
    len = strlen(s) - 1; // Subtract 1 to exclude the newline character

    scanf("%d", &m);
    t = 0;
    for (i = 0; i < m; i++) {
      scanf("%d", &h);
      t += h;
    }

    for (i = 0; i < len; i++) {
      printf("%c", s[(t + i) % len]);
    }
    printf("\n");
  }

  return 0;
}