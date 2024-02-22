#include <stdio.h>

int main() {
  int a[4];
  
  while (1) {
    for (int i = 0; i < 4; ++i) {
      scanf("%d", &a[i]);
    }
    
    if (a[0] == 0) {
      break;
    }
    
    printf("%d+%d+%d+%d\n", a[0], a[1], a[2], a[3]);
  }
  
  return 0;
}