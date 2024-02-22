#include <stdio.h>
#include <string.h>

int main() {
  char s[201];
  int m, a, i;

  while (scanf("%s%d", s, &m) == 2 && s[0] != '-') {
    a = strlen(s);

    // Calculate the sum t
    int t = 0;
    for (i = 0; i < m; i++) {
      int h;
      scanf("%d", &h);
      t += h;
    }

    // Print the characters
    for (i = 0; i < a; i++) {
      putchar(s[(t + i) % a]);
    }
    putchar('\n');
  }

  return 0;
}