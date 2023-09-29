#include <stdio.h>
int main() {
  for (int i = 1; i < 10; i++) {
    for (int j = i + 1; j < 10; j++) {
      printf("%dx%d=%d\n", i, j, i * j);
    }
  }
  return 0;
}
