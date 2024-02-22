#include <stdio.h>
#include <string.h>

int main() {
  int n, t[999];
  int i;

  while (scanf("%d", &n) && n) {
    memset(t, 0, sizeof(t));

    for (; n--; t[i] = *t)
      scanf(" %d %d", &i, t);

    for (scanf("%d", &n); n--; putchar(t[i]))
      scanf(" %d", &i);

    putchar('\n');
  }

  return 0;
}