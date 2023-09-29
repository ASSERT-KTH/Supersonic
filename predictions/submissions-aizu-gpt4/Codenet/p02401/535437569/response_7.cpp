#include <cstdio>
using namespace std;
int main() {
  int x, y, result;
  char z;
  while (scanf("%d %c %d", &x, &z, &y), z != '?') {
    result = (z == '+') ? x + y : (z == '-') ? x - y : (z == '/') ? x / y : (z == '*') ? x * y : 0;
    printf("%d\n", result);
  }
  return 0;
}