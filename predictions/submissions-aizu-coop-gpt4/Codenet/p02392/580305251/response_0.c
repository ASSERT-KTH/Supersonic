#include <stdio.h>

int main(void) {
  int a, b, c;
  
  if(scanf("%d %d %d", &a, &b, &c) != 3) {
    printf("Error: Expected 3 inputs\n");
    return 1;
  }
  
  if (a < b && b < c) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  
  return 0;
}