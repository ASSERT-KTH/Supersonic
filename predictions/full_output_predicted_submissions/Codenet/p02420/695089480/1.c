#include <string.h>
main() {
  char s[201];
  for (; scanf("%s%d", s, &m), s[0] != '-'; puts("")) {
    a = strlen(s);
    for (i = t = 0; i < m; scanf("%d", &h), t += h, i++)
      ;
    for (i = 0; i < a; printf("%c", s[(t + i++) % a]))
      ;
  }
}
