#include <stdio.h>

int main() {
  int a, b, temp;
  scanf("%d%d", &a, &b);
  
  while (b != 0) {
    if (b & 1) {  // equivalent to b % 2
      temp = a % b;
      a = b;
      b = temp;
    } else {
      b >>= 1;  // equivalent to b = b / 2
    }
  }
  
  printf("%d\n", a);
  
  return 0;
}