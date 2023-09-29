#include <cstdio>
#include <cstring>

int main() {
  char s[201];
  while(scanf("%s", s) && s[0] != '-') {
    int m;
    scanf("%d", &m);
    int a = strlen(s);
    int t = 0;
    for (int i = 0; i < m; ++i) {
      int h;
      scanf("%d", &h);
      t = (t + h) % a;
    }
    printf("%s%s\n", s + t, s);
    s[t] = '\0';
  }
  return 0;
}