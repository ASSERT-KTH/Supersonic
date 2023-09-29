#include <string.h>
#include <stdio.h>
int m, h, a;
int main() {
  char s[201];
  while (scanf("%s%d", s, &m) == 2 && s[0] != '-') {
    a = strlen(s);
    int t = 0;
    for (int i = 0; i < m; i++) {
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