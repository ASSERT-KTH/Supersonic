#include <stdio.h>
#include <string.h>

int main() {
  int n;
  int t[999];
  
  while (scanf("%d", &n) == 1 && n > 0) {
    memset(t, 0, sizeof(t));
    
    while (n--) {
      int i;
      char c1, c2;
      
      scanf("%d %c %c", &i, &c1, &c2);
      t[i] = t[c2];
    }
    
    scanf("%d", &n);
    
    while (n--) {
      int i;
      scanf("%d", &i);
      printf("%c", !t[i] * i + t[i]);
    }
    
    printf("\n");
  }
  
  return 0;
}