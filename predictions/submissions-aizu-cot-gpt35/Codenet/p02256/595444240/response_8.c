#include <stdio.h>

int main() {
  int a, b, c, i;
  scanf("%d%d", &a, &b);
  
  c = a % b;
  while (c) {
    a ^= b;
    b ^= a;
    a ^= b;
    b ^= c;
    c = a % b;
  }
  
  printf("%d", a);
  return 0;
}