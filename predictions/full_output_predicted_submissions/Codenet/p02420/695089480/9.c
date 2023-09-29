#include <string.h>
i, m, h, t, a;
main() {
  char s[201];
  for (; scanf("%s%d", s, &m), s[0] != '-'; puts("")) {
    a = strlen(s);
    for (i = t = 0; i < m; printf("%d", s[(t + i++) % a]))
      ;
    for (i = 0; i < a; printf("%c", s[(t + i++) % a]))
      ;
  }
}
