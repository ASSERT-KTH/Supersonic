#include <stdio.h>

int main(void) {
  int a, b, c;
  if(scanf("%d %d %d", &a, &b, &c) == 3 && a < b && b < c) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
}