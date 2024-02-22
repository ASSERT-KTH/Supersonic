#include <stdio.h>

int b, d = 0;

int main() {
  scanf("%d", &b);
  
  for (int i = 0; i < b; i++) {
    int num;
    scanf("%d", &num);
    d += num;
  }
  
  printf("%d\n", d);
  return 0;
}