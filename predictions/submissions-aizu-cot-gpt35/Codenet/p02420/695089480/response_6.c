#include <stdio.h>
#include <string.h>

int main() {
  char s[201];
  int m, t, h;
  while (scanf("%s%d", s, &m) == 2 && s[0] != '-') {
    int len = strlen(s);
    for (int i = 0, t = 0; i < len; i++, t += h) {
      scanf("%d", &h);
      printf("%c", s[(t + i) % len]);
    }
    printf("\n");
  }
  return 0;
}