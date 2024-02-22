#include <stdio.h>

int main() {
  // Only iterate from 1 to 9 once to reduce redundant iterations
  for (int i = 1; i < 10; i++) {
    // Use a single printf statement to print the entire multiplication table
    printf("%dx1=%d\n", i, i);
    printf("%dx2=%d\n", i, i * 2);
    printf("%dx3=%d\n", i, i * 3);
    printf("%dx4=%d\n", i, i * 4);
    printf("%dx5=%d\n", i, i * 5);
    printf("%dx6=%d\n", i, i * 6);
    printf("%dx7=%d\n", i, i * 7);
    printf("%dx8=%d\n", i, i * 8);
    printf("%dx9=%d\n", i, i * 9);
  }

  return 0;
}