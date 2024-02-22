#include <stdio.h>

int main() {
  char table[256];
  int index = 0;

  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      index += sprintf(table + index, "%dx%d=%d\n", i, j, i * j);
    }
  }

  printf("%s", table);

  return 0;
}