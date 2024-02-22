#include <cstdio>
#include <cstring>

int main() {
  char s[201];
  int m, a, t;
  
  while (scanf("%s%d", s, &m) == 2 && s[0] != '-') {
    a = strlen(s);
    t = 0;

    for (int i = 0; i < m; ++i) {
      scanf("%d", &t);
    }

    for (int i = 0; i < a; ++i) {
      printf("%c", s[(t + i) % a]);
    }

    printf("\n");
  }

  return 0;
}