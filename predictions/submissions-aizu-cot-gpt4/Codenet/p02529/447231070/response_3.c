#include <stdio.h>

int main() {
  int a, b, d = 0, c[100] = {0};
  
  scanf("%d", &a);
  for (; a--; ) {
    scanf("%d", &b);
    c[b] = 1;
  }
  
  scanf("%d", &a);
  for (; a--; ) {
    scanf("%d", &b);
    d += c[b];
  }
  
  printf("%d\n", d);
  return 0;
}