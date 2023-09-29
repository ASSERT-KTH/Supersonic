#include <cstdio>
using namespace std;
int main() {
  int x, y;
  char z;
  while (scanf("%d %c %d", &x, &z, &y) == 3) {
    switch (z) {
      case '+':
        printf("%d\n", x + y);
        break;
      case '-':
        printf("%d\n", x - y);
        break;
      case '*':
        printf("%d\n", x * y);
        break;
      case '/':
        if (y == 0) {
          printf("ERROR\n");
        } else {
          printf("%d\n", x / y);
        }
        break;
      case '?':
        return 0;
      default:
        printf("ERROR\n");
    }
  }
  return 0;
}