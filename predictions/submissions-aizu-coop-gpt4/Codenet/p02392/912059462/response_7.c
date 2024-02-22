#include <stdio.h>

int main() {
  int a, b, c;
  a = getchar() - '0';
  getchar(); // remove white space
  b = getchar() - '0';
  getchar(); // remove white space
  c = getchar() - '0';

  if (a < b && b < c) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}