#include <stdio.h>

int main() {
  int a[4];
  
  while (1) {
    if (scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]) != 4) {
      break;
    }
    
    if (a[0] == 0) {
      break;
    }
    
    printf("%*s%d+%d+%d+%d\n", 110000, "(", a[0], a[1], a[2], a[3]);
  }
  
  return 0;
}