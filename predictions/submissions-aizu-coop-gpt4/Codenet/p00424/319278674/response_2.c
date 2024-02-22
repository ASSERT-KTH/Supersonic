#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 999

int main() {
  int n, i;
  char *t = (char *)malloc(MAX_SIZE * sizeof(char));

  while (scanf("%d", &n) != EOF) {
    memset(t, 0, MAX_SIZE * sizeof(char));
    for (; n--; ) {
      scanf(" %c", &i);
      scanf(" %c", &t[i]);
    }
    scanf("%d", &n);
    for (; n--; ) {
      scanf(" %c", &i);
      putchar(t[i] ? t[i] : i);
    }
    putchar('\n');
  }

  free(t);
  return 0;
}