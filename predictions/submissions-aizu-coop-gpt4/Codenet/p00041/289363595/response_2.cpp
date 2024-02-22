#include <stdio.h>
#include <string.h>

#define NUM_CHARS 110000

int main() {
  char buffer[NUM_CHARS + 1];
  memset(buffer, '(', NUM_CHARS);
  buffer[NUM_CHARS] = '\0';  // Null-terminate the string

  int a[4];
  char input[50];

  while (1) {
    fgets(input, 50, stdin);
    sscanf(input, "%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);

    if (a[0] == 0) {
       break;
    }

    printf("%s", buffer);
    printf("%d+%d+%d+%d", a[0], a[1], a[2], a[3]);
    putchar('\n');
  }
  return 0;
}