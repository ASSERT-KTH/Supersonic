#include <stdio.h>
#include <string.h>

#define MAX 999

int main() {
  int a, b, d = 0, c[MAX] = {0};

  scanf("%d", &a);
  while(a--)
  {
    scanf("%d", &b);
    c[b] = 1;
  }
  
  scanf("%d", &a);
  while(a--)
  {
    scanf("%d", &b);
    d += c[b];
  }
  
  printf("%d\n", d);
  return 0;
}