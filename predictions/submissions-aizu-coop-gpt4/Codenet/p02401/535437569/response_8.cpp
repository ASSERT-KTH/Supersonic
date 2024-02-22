#include <cstdio>
using namespace std;
int main() {
  int x, y, result;
  char z;
  while (1) {
    scanf("%d %c %d", &x, &z, &y);
    switch(z) {
      case '?':
        return 0;
      case '+':
        result = x + y;
        break;
      case '-':
        result = x - y;
        break;
      case '/':
        result = x / y;
        break;
      case '*':
        result = x * y;
        break;
      default:
        continue;
    }
    printf("%d\n", result);
  }
  return 0;
}