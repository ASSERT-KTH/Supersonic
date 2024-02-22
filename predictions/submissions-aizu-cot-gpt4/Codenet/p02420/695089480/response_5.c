#include <string.h>
i, m, t, a;
main() {
  char s[201];
  char output[201];
  for (; scanf("%s%d", s, &m), s[0] != '-'; puts("")) {
    a = strlen(s);
    for (i = t = 0; i < m; i++)
      scanf("%d", &t);
    for (i = 0; i < a; i++)
      output[i] = s[(t + i) % a];
    output[i] = '\0';
    printf("%s\n", output);
  }
}