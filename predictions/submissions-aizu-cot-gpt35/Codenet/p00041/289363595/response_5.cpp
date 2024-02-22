#include <stdio.h>

int main() {
  int a, b, c, d;
  
  do {
    scanf("%d", &a);
    if (a == 0) {
      break;
    }
    scanf("%d %d %d", &b, &c, &d);
    printf("%d+%d+%d+%d\n", a, b, c, d);
  } while (1);
}