#include <cstdio>
using namespace std;
int main() {
  int x, y;
  char z;
  char buffer[50];
  while (1) {
    scanf("%d %c %d", &x, &z, &y);
    switch (z) {
        case '?':
            return 0;
        case '+':
            sprintf(buffer, "%d", x + y);
            puts(buffer);
            break;
        case '-':
            sprintf(buffer, "%d", x - y);
            puts(buffer);
            break;
        case '/':
            if (y != 0) {
                sprintf(buffer, "%d", x / y);
                puts(buffer);
            }
            break;
        case '*':
            sprintf(buffer, "%d", x * y);
            puts(buffer);
            break;
    }
  }
}