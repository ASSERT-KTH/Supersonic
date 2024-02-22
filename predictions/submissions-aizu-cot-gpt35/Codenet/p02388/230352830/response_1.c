#include <stdio.h>

int main(void) {
  int x;
  scanf("%d", &x);
  
  if (x >= 0) {
    printf("%d\n", x * x * x);
  } else {
    printf("Negative input is not allowed.\n");
  }
  
  return 0;
}