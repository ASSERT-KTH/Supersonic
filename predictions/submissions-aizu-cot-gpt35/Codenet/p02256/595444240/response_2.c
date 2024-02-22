#include <stdio.h>

int main() {
  int a, b, c;
  scanf("%d%d", &a, &b);
  
  do {
    c = a % b;
    a = b;
    b = c;
  } while (c > 0);
  
  printf("%d\n", a);
}