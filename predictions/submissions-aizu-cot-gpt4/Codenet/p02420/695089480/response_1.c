#include <string.h>
i, m, h, t, a, j;
main() {
  char s[201];
  for (; fread(s, 1, 200, stdin) && s[0] != '-'; puts("")) {
    a = strlen(s);
    for (i = t = 0; i < m; fread(&h, sizeof(int), 1, stdin), t += h, i++)
      ;
    j = t % a;
    for (i = 0; i < a; fwrite(&s[(j + i++) % a], 1, 1, stdout))
      ;
  }
}