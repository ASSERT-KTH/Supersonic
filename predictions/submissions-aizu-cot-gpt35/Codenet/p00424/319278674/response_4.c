#include <stdio.h>

int main() {
  int n;
  char t[999];
  
  while (scanf("%d", &n) && n) {
    for (int i = 0; i < n; i++) {
      scanf(" %c %c", &i, t);
      t[i] = *t;
    }
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
      scanf(" %c", &i);
      putchar(t[i]);
    }
    
    putchar('\n');
  }
  
  return 0;
}