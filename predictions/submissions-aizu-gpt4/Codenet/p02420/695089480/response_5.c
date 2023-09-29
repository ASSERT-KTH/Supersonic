#include <cstring>
#include <cstdio>
char s[201];
int i, m, h, t, a;
int main() {
  while (scanf("%s%d", s, &m), s[0] != '-') {
    a = strlen(s);
    t = 0;
    for (i = 0; i < m; ++i) {
      scanf("%d", &h);
      t = (t + h) % a;
    }
    puts(&s[t]);
    puts(&s[0]);
  }
  return 0;
}