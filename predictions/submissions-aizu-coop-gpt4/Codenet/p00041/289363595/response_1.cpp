#include <stdio.h>
#include <string.h>

int main() {
  int a[4];
  char buffer[110001];

  memset(buffer, '(', 110000);  // Fill buffer with '('
  buffer[110000] = '\0';  // Null-terminate the buffer

  while (1) {
    for (int i = 0; i < 4; ++i) {
      scanf("%d", &a[i]);
    }
    if (a[0] == 0) {
      break;
    }

    fputs(buffer, stdout);  // Print 110000 '(' characters
    printf("%d+%d+%d+%d\n", a[0], a[1], a[2], a[3]);
  }
}