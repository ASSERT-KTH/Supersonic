#include <string.h>
i, m, h, t, a;
main() {
  char s[201];
  for (; scanf("%s%d", s, &m), s[0] != '-'; puts("")) {
    a = strlen(s);
    for (i = t = 0; i < m; scanf("%d", &h), t += h, i++)
      ;
    for (i = 0; s[(t + i++) % a] != '\0'; printf("%c", s[(t + i++) % a]))
      ;
  }
}
