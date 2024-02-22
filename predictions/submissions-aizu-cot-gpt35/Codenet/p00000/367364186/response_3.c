#include <stdio.h>

int main() {
  for (int j = 1; j < 10; j++) {
    for (int i = 1; i < 10; i++) {
      printf("%dx%d=%-2d ", i, j, i * j);
    }
    printf("\n");
  }

  return 0;
}