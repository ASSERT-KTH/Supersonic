#include <stdio.h>

int main() {
  int a, b, c, d;
  
  while (1) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    
    if (a == 0) {
      break;
    }
    
    putchar('(');
    putchar(a + '0');
    putchar('+');
    putchar(b + '0');
    putchar('+');
    putchar(c + '0');
    putchar('+');
    putchar(d + '0');
    putchar(')');
    putchar('\n');
  }
}