#include <stdio.h>
int main() {
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      int result = i*j;
      printf("%dx%d=%d\n", i, j, result);
    }
  }
  return 0;
}