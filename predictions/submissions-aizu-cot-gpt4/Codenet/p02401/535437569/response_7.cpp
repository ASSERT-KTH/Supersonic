#include <cstdio>
using namespace std;
int main() {
  int x, y;
  char z;
  while (1) {
    scanf("%d %c %d", &x, &z, &y);
    switch (z) {
      case '?':
        return 0;
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
  }
  return 0;
}