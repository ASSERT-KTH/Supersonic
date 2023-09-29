#include <string.h>
#include <iostream>
using namespace std;
int main() {
  int i, m, h, t, a;
  char s[201];
  while (scanf("%s%d", s, &m), s[0] != '-') {
    a = strlen(s);
    for (i = t = 0; i < m; scanf("%d", &h), t += h, i++);
    for (i = 0; i < a; printf("%c", s[(t + i++) % a]));
    printf("\n");
  }
  return 0;
}