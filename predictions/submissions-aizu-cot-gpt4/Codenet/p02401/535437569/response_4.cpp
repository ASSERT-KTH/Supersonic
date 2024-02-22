#include <cstdio>

int main() {
  int x, y;
  char z;

  while (1) {
    scanf("%d %c %d", &x, &z, &y);

    if (z == '?') {
      return 0;
    }

    switch (z) {
      case '+':
        printf("%d\n", x + y);
        break;
      case '-':
        printf("%d\n", x - y);
        break;
      case '/':
        if (y != 0) {
          printf("%d\n", x / y);
        }
        break;
      case '*':
        printf("%d\n", x * y);
        break;
    }
  }

  return 0;
}