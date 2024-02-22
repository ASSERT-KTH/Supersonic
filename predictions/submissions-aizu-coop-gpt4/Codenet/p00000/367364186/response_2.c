#include <stdio.h>

int main() {
  for (int i = 1; i < 10; i++) {
    printf("%d", i);
    for (int j = 1; j < 10; j++) {
      printf("x%d=%d ", j, i * j);
    }
    printf("\n");
  }
  return 0;
}