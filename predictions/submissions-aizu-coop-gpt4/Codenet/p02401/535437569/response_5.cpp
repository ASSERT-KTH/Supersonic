#include <cstdio>
using namespace std;

int main() {
  int x, y, result;
  char z;
  while (1) {
    scanf("%d %c %d", &x, &z, &y);
    if (z == '?') {
      return 0;
    }

    switch (z) {
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