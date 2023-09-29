#include <stdio.h>

int main() {
  int result[10][10] = {0};
  for (int i = 1; i < 10; ++i) {
    for (int j = 1; j < 10; ++j) {
      if (result[i][j] == 0) {
        result[i][j] = result[j][i] = i * j;
      }
      printf("%dx%d=%d\n", i, j, result[i][j]);
    }
  }
  return 0;
}