#include <cstdio>

int main() {
  int x, y;
  char z;
  while (1) {
    scanf("%d %c %d", &x, &z, &y);
    switch (z) {
      case '?':
        break;
      case '+':
        printf("%d\n", x + y);
        break;
      case '-':
        printf("%d\n", x - y);
        break;
      case '/':
        printf("%d\n", x / y);
        break;
      case '*':
        printf("%d\n", x * y);
        break;
    }
    if (z == '?') {
      break;
    }
  }
  return 0;
}