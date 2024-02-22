#include <stdio.h>

int main() {
  int a;
  while (1) {
    scanf("%d", &a);
    if (a == 0) {
      break;
    }
    printf("(%d+%d+%d+%d)\n", a, a, a, a);
  }
}