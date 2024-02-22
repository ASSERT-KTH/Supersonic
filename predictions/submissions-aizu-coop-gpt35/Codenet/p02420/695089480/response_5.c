#include <stdio.h>

int main() {
  int i, m, h, t, a;
  char s[201];

  while (scanf("%200s%d", s, &m) == 2 && s[0] != '-') {
    a = strlen(s);
    printf("\n");
    
    for (i = t = 0; i < m; i++) {
      scanf("%d", &h);
      t += h;
    }

    for (i = 0; i < a; i++) {
      int idx = (t + i) % a;
      printf("%c", s[idx]);
    }
  }

  return 0;
}