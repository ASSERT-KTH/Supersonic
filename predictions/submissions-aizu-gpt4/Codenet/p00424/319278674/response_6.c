#include <stdio.h>
#include <string.h>

#define MAX 999

int n;
char t[MAX] = {0};

int main() {
  int i;
  while (scanf("%d", &n) != EOF) {
    memset(t, 0, sizeof(t));
    for (; n--; t[i] = *t)
      scanf(" %c", &i);
    for (scanf("%d", &n); n--; putchar(t[i] ? t[i] : i))
      scanf(" %c", &i);
  }
  return 0;
}