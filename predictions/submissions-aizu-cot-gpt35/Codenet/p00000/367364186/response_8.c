#include <stdio.h>

int main() {
  for (int i = 2; i < 10; i++) {
    for (int j = 2; j < 10; j++) {
      printf("%dx%d=%d\n", i, j, i * j);
    }
  }
  return 0;
}