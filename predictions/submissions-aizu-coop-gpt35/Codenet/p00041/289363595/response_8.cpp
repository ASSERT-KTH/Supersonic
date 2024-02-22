#include <stdio.h>

int main() {
  char line[256];
  int sum;

  while (1) {
    fgets(line, sizeof(line), stdin);

    sscanf(line, "%d %d %d %d", &sum, &sum, &sum, &sum); // Parse integers from the line

    if (sum == 0) {
      break;
    }

    for (int i = 0; i < 110000; ++i) {
      putchar('(');
    }

    printf("%d+%d+%d+%d\n", sum, sum, sum, sum); // Print the sum

  }
  return 0;
}