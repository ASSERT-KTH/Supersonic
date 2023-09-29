#include <cstdio>
using namespace std;
int main() {
  int x, y;
  char z;
  while (scanf("%d %c %d", &x, &z, &y), z != '?') {
    if (z == '+') {
      printf("%d\n", x + y);
    } else if (z == '-') {
      printf("%d\n", x - y);
    } else if (z == '/') {
      printf("%d\n", x / y);
    } else if (z == '*') {
      printf("%d\n", x * y);
    }
  }
  return 0;
}