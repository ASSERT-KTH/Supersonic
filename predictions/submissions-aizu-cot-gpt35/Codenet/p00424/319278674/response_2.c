#include <stdio.h>
#include <string.h>

int main() {
  int n;
  int t[999];
  
  while (scanf("%d", &n) && n) {
    memset(t, 0, sizeof(t));
    
    for (int loop_var = 0; loop_var < n; loop_var++) {
      char c1, c2;
      scanf(" %c %c", &c1, &c2);
      t[c1] = c2;
    }
    
    scanf("%d", &n);
    
    for (int loop_var = 0; loop_var < n; loop_var++) {
      char c;
      scanf(" %c", &c);
      putchar(t[c]);
    }
    
    putchar('\n');
  }
  
  return 0;
}