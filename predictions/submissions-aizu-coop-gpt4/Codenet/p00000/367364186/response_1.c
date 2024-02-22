#include <stdio.h>
int main() {
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      int product = i * j;  // Store the multiplication result
      printf("%dx%d=%d\n", i, j, product);
    }
  }
  return 0;
}