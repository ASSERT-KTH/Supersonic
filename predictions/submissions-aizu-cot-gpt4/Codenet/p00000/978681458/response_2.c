#include <stdio.h>

int main(void) {
  constexpr int limit = 10;
  for (int i = 1; i < limit; i++) {
    for (int j = 1; j < limit; j++) {
      int multiplication = i * j;
      printf("%dx%d=%d\n", i, j, multiplication);
    }
  }
  return 0;
}