#include <stdio.h>
#include <stdlib.h>

int main() {
  int size = 9;
  int** table = (int**)malloc(size * sizeof(int*));

  for (int i = 0; i < size; i++) {
    table[i] = (int*)malloc(size * sizeof(int));
  }

  for (int i = 2; i <= size; i++) {
    for (int j = 2; j <= size; j++) {
      table[i - 2][j - 2] = i * j;
    }
  }

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%dx%d=%d\n", i + 1, j + 1, table[i][j]);
    }
  }

  for (int i = 0; i < size; i++) {
    free(table[i]);
  }
  free(table);

  return 0;
}