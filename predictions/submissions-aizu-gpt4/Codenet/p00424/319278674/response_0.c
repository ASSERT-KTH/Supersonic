#include <stdio.h>
#include <string.h>

#define SIZE 999

char t[SIZE];

int main() {
  int n, i;
  while(scanf("%d", &n) == 1 && n) {
    memset(t, 0, sizeof(t));
    while(n--) {
      scanf(" %c", &i);
      t[i] = getchar();
    }
    scanf("%d", &n);
    while(n--) {
      scanf(" %c", &i);
      putchar(t[i] ? t[i] : i);
    }
    putchar('\n');
  }
  return 0;
}