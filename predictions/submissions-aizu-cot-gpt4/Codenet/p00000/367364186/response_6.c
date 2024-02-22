#include <stdio.h>

int main() {
  char buffer[32];

  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      sprintf(buffer, "%dx%d=%d ", i, j, i * j);
      printf("%s", buffer);
    }
    putchar('\n');
  }
}