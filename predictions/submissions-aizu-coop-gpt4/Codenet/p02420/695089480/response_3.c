#include <stdio.h>
#include <string.h>

int i, m, h, t, a;

int main() {
  char s[201];
  for (; scanf("%s%d", s, &m), s[0] != '-'; puts("")) {
    a = strlen(s);
    for (i = t = 0; i < m; i++) {
      scanf("%d", &h);
      t += h;
    }
    for (i = 0; i < a; i++) {
      int index = (t + i) % a;  // Compute the index only once
      printf("%c", s[index]);
    }
  }
  return 0;
}