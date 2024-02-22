#include <string.h>

int main() {
  char s[201];
  int i, m, h, t, a;
  while(scanf("%s%d", s, &m), s[0] != '-') {
    a = strlen(s);
    t = 0;
    for (i = 0; i < m; i++) {
      scanf("%d", &h);
      t += h;
    }
    for (i = 0; i < a; i++) {
      putchar(s[(t + i) % a]);
    }
    putchar('\n');
  }
  return 0;
}