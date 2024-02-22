#include <stdio.h>

int main() {
  int a, b, d = 0;
  
  scanf("%d", &b);
  
  for (a = b; a--; ) {
    int num;
    scanf("%d", &num);
    d++;
  }
  
  printf("%d\n", d);
  
  return 0;
}