#include <stdio.h>

int main() {
  char table[1000]; // A buffer to hold the multiplication table
  int index = 0;

  for (int counter = 1; counter <= 81; counter++) {
    int i = (counter - 1) / 9 + 1;
    int j = (counter - 1) % 9 + 1;

    index += sprintf(table + index, "%dx%d=%d\n", i, j, i * j);
  }

  printf("%s", table);

  return 0;
}