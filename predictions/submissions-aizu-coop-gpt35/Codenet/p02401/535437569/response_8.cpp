#include <cstdio>
using namespace std;

int main() {
  int x, y;
  char z;
  char input[20];

  while (1) {
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d %c %d", &x, &z, &y);

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
  
  return 0;
}