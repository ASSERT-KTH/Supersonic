#include <stdio.h>
int main() {
  int a[4];
  char buffer[110005];
  memset(buffer, '(', 110000);
  buffer[110000] = '\n';
  buffer[110001] = '\0';
  while (scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]), a[0]) {
    printf("%s%d+%d+%d+%d\n", buffer, a[0], a[1], a[2], a[3]);
  }
  return 0;
}