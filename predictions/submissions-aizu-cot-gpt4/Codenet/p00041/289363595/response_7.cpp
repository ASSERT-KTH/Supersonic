#include <stdio.h>
int main() {
  int a[4];
  while (1) {
    for (int i = 0; i < 4; ++i) {
      scanf("%d", &a[i]);
      if (i == 0 && a[0] == 0) {
        return 0;
      }  
    }
    printf("%0*c", 110000, '(');
    printf("%d+%d+%d+%d\n", a[0], a[1], a[2], a[3]);
  }
  return 0;
}