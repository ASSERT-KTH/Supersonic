#include <stdio.h>
int main(void) {
  int x;
  if(scanf("%d", &x)){
    int result = x * x;
    printf("%d\n", result * x);
  }
  return 0;
}