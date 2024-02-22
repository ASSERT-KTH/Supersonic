#include <stdio.h>
#include <string.h>

int i, m, h, t, a;
char s[201], new_s[201];

int main() {
  while (scanf("%s%d", s, &m), s[0] != '-') {
    a = strlen(s);
    for (i = t = 0; i < m; scanf("%d", &h), t += h, i++)
      ;
    for (i = 0; i < a; i++)
      new_s[i] = s[(t + i) % a];
    new_s[i] = '\0';
    puts(new_s);
    puts("");
  }
  return 0;
}