#include <cstdio>
using namespace std;
int main() {
  int x, y;
  char z;
  while (scanf("%d %c %d", &x, &z, &y) != EOF) {
    switch(z) {
      case '+': printf("%d\n", x + y); break;
      case '-': printf("%d\n", x - y); break;
      case '*': printf("%d\n", x * y); break;
      case '/':
          if(y == 0) {
              printf("Divide by zero error\n");
              break;
          }
          printf("%d\n", x / y);
          break;
      case '?': return 0;
      default: printf("Invalid operator\n");
    }
  }
  return 0;
}