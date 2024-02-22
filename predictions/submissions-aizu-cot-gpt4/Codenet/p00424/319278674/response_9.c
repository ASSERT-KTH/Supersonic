#include <stdio.h>
#include <string.h>

int n, t[999];
int main(void) {
  char i;
  while (scanf("%d", &n) == 1) {
    memset(t, 0, sizeof t);
    while (n--) {
      scanf(" %c", &i);
      t[i] = *t;
    }
    if(scanf("%d", &n) == 1) {
      while (n--) {
        scanf(" %c", &i);
        putchar(!t[i] * i + t[i]);
      }
    }
    puts("");
  }
  return 0;
}