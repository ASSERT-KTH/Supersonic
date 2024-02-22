#include <string.h>

int main() {
  char s[201];
  int m, h, t, a;
  
  while (scanf("%s%d", s, &m), s[0] != '-') {
    a = strlen(s);
    t = 0;
    
    for (int i = 0; i < m; i++) {
      scanf("%d", &h);
      t = (t + h) % a;  // Optimize rotation calculation
    }
  
    for (int i = 0; i < a; i++) {
      printf("%c", s[(t + i) % a]);
    }
  
    putchar('\n');  // Print new line more efficiently
  }

  return 0;
}