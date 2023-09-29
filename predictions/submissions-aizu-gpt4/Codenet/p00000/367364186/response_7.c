#include <stdio.h>
int main() {
  int i, j, res;
  for (i = 1; i < 10; ++i) {
    for (j = 1; j < 10; ++j) {
      res = i * j;
      printf("%dx%d=%d\n", i, j, res);
    }
  }
  return 0;
}