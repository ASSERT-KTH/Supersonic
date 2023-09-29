#include <stdio.h>
#include <string.h>

int main() {
  char s[201] = {0};
  int t = 0, a = 0, m = 0, h = 0, i = 0;

  while (scanf("%s %d", s, &m), s[0] != '-') {
    a = strlen(s);
    t = 0;
    for (i = 0; i < m; ++i) {
      scanf("%d", &h);
      t = (t + h) % a;
    }
    for (i = 0; i < a; ++i) {
      printf("%c", s[(t + i) % a]);
    }
    printf("\n");
  }
  
  return 0;
}