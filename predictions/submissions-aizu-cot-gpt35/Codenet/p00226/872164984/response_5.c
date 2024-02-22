#include <stdio.h>
#include <string.h>

int main() {
  int R[256] = {0};
  int c;
  
  for (int i = 0, h = 0, b = 0; read(0, &c, 1); ++i > 9 && memset(R, 1, 232)) {
    b += !!R[c];
    h += !(R[c] = 1);
    
    if (i > 9) {
      putchar('0' + h);
      putchar(' ');
      putchar('0' + (b - h));
      putchar('\n');
    }
  }
  
  return 0;
}