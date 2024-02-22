#include <stdio.h>

int main(void) {
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j <= i; j++) {
      printf("%dx%d=%d\n", j, i, i * j); // Print the multiplication table symmetrically
    }
  }
  return 0;
}