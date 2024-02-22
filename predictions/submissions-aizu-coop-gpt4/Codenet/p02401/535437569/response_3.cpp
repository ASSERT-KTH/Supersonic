#include <cstdio>

int main() {
  int x, y;
  char z;
  while (true) {
    scanf("%d %c %d", &x, &z, &y);
    switch(z) {
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
      case '?':
        return 0;
    }
  }
  return 0;
}