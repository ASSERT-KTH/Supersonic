#include <stdio.h>

int main() {
  int a[4];
  do {
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);
    if (a[0] == 0) {
      break;
    }
    printf("%d+%d+%d+%d\n", a[0], a[1], a[2], a[3]);
  } while (1);

  return 0;
}