#include <stdio.h>
int main(void) {
  int a = 0, b = 0, c = 0;
  if (scanf("%d %d %d", &a, &b, &c) != 3) {
    puts("Failed to read input");
    return 1; 
  }
  if (a >= 0 && a <= 100 && b >= 0 && b <= 100 && c >= 0 && c <= 100) {
    if (a < b && b < c) {
      puts("Yes");
    } else {
      puts("No");
    }
  } else {
    puts("Input values are out of range");
    return 1;
  }
  return 0;
}