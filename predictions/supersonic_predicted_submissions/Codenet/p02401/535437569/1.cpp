#include <stdio.h>
int main() {
  int x, y;
  char z;
  while (1) {
    cin >> x >> z >> y;
    if (z == '?') {
      return 0;
    } else if (z == '+') {
      printf("%d\n", x + y);
    } else if (z == '-') {
      printf("%d\n", x - y);
    } else if (z == '/') {
      printf("%d\n", x / y);
    } else if (z == '*') {
      printf("%d\n", x * y);
    }
  }
  return 0;
}
