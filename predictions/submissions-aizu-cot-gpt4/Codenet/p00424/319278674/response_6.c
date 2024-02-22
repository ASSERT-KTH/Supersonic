#include <stdio.h>
#include <string.h>  

int n, t[999], i;
char c;

int main() {
  while (scanf("%d", &n) != EOF) {
    if (n == 0) break;
    memset(t, 0, sizeof t);
    for (; n--; t[i] = *t) {
      scanf(" %c %c", &c, (char*)t);
      i = c;
    }
    scanf("%d", &n);
    for (; n--; ) {
      scanf(" %c", &c);
      i = c;
      if (t[i] != 0) putchar(i);
    }
    puts("");
  }
  return 0;
}