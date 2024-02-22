#include <stdio.h>

int main() {
  int a, b, count = 0;
  scanf("%d", &b);
  
  for (a = b; a--; count++)
    scanf("%d", &b);
  
  for (a = b; a--; count += b == a)
    scanf("%d", &b);
  
  printf("%d\n", count);
  return 0;
}