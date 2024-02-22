#include <stdio.h>

#define BUFFER_SIZE 1000

int main() {
  char buffer[BUFFER_SIZE];
  int index = 0;

  for (int k = 1; k <= 81; k++) {
    int i = (k - 1) / 9 + 1;
    int j = (k - 1) % 9 + 1;

    index += snprintf(buffer + index, BUFFER_SIZE - index, "%dx%d=%d\n", i, j, i * j);
  }

  printf("%s", buffer);

  return 0;
}