#include <stdio.h>
#include <string.h>

int n, t[999];
char x, y;

int main() {
  while (scanf("%d", &n) && n) {
    memset(t, 0, sizeof(t));
    for (int i = 0; i < n; i++) {
      scanf(" %c %c", &x, &y);
      t[x] = y;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf(" %c", &x);
      putchar(t[x] ? t[x] : x);
    }
    puts("");
  }
  return 0;
}