#include <stdio.h>

int main() {
  int a[4];
  char buffer[110005];

  memset(buffer, '(', 110000);
  buffer[110000] = '\0';

  while (1) {
    if (scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]) != 4 || a[0] == 0) {
      break;
    }
    printf("%s%d+%d+%d+%d\n", buffer, a[0], a[1], a[2], a[3]);
  }
  return 0;
}