#include <cstdio>
using namespace std;
int main() {
  int x, y;
  char z;
  for(;;) {
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
        if (y != 0) {
          printf("%d\n", x / y);
        } else {
          printf("Error: Division by zero\n");
        }
        break;
      case '*':
        printf("%d\n", x * y);
        break;
    }
  }
  return 0;
}