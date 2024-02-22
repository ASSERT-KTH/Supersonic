#include <stdio.h>
#include <string.h>

int main() {
  int a[4];
  char parens[110001];
  memset(parens, '(', 110000);
  parens[110000] = '\0';

  while (1) {
    scanf("%d", &a[0]);
    if (a[0] == 0) {
      break;
    }
    for (int i = 1; i < 4; ++i) {
      scanf("%d", &a[i]);
    }
    printf("%s%d+%d+%d+%d\n", parens, a[0], a[1], a[2], a[3]);
  }
  return 0;
}