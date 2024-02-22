#include <stdio.h>
#include <string.h>

int main() {
  int n, t[999];

  for (; scanf("%d", &n) && n; ) {
    memset(t, 0, sizeof(t));

    for (; n--; t[i] = t[0])
      scanf(" %c %c", &i, t);

    for (; n--; putchar(t[i] ? t[i] : i))
      scanf(" %c", &i);
  }

  return 0;
}