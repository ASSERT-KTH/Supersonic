#include <stdio.h>
int main() {
  int a, b, c;
  if (scanf("%d%d%d", &a, &b, &c) == 3 && a < b && b < c) {
    puts("Yes");
  } else {
    puts("No");
  }
  return 0;
}