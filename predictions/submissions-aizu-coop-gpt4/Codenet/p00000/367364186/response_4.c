#include <stdio.h>

int main() {
  char buffer[400];
  for (int i = 1; i < 10; i++) {
    int offset = 0;
    for (int j = 1; j < 10; j++) {
      offset += sprintf(buffer + offset, "%dx%d=%d\n", i, j, i * j);
    }
    printf("%s", buffer);
  }
  return 0;
}