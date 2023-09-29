#include <cstdio>
using namespace std;
int main() {
  int x, y;
  char z;
  while (scanf("%d %c %d", &x, &z, &y), z != '?') {
    printf("%d\n", z == '+' ? x + y : z == '-' ? x - y : z == '/' ? x / y : x * y);
  }
  return 0;
}