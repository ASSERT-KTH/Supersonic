#include <cstdio>
using namespace std;
int main() {
  int x, y;
  char z;
  while (1) {
    scanf("%d %c %d", &x, &z, &y);
    if (z == '?') {
      return 0;
    } else if (z == '+') {
      printf("%d\n", x + y);
    } else if (z == '-') {
      printf("%d\n", x - y);
    } else if (z == '/') {
      printf("%d\n", x / y);
    } else if (z == '*') {
      printf("%d\n", x * y);
    }
  }
}
