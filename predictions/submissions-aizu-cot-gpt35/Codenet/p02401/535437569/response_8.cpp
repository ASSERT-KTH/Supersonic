#include <cstdio>
using namespace std;

int main() {
  int x, y;
  char z;
  int result;
  
  while (scanf("%d %c %d", &x, &z, &y) == 3) {
    switch (z) {
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
    }
    printf("%d\n", result);
  }
  
  return 0;
}