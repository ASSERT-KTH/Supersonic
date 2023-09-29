#include <stdio.h>

int main() {
  int a[4];
  char buffer[110004];

  while (1) {
    if (scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]), a[0] == 0)
      break;

    memset(buffer, '(', 110000);
    buffer[110000] = '\0';

    printf("%s%d+%d+%d+%d\n", buffer, a[0], a[1], a[2], a[3]);
  }
}