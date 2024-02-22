#include <stdio.h>
int main() {
  int a[4];
  char str[110001];
  memset(str, '(', 110000);
  str[110000] = '\0';
  while (1) {
    scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]);
    if (a[0] == 0) {
      break;
    }
    printf("%s%d+%d+%d+%d\n", str, a[0], a[1], a[2], a[3]);
  }
}