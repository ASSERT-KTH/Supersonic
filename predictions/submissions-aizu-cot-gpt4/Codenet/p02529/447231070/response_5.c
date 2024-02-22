#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int a, b, d = 0, max_b = 0;
  int* c = NULL;

  scanf("%d", &a);
  c = (int*)malloc((a+1) * sizeof(int));
  memset(c, 0, (a+1) * sizeof(int));
  
  for (int i = a; i--; ) {
    scanf("%d", &b);
    c[b] = 1;
    if (b > max_b) max_b = b;
  }
  
  c = (int*)realloc(c, (max_b+1) * sizeof(int));
  
  scanf("%d", &a);
  
  for (int i = a; i--; ) {
    scanf("%d", &b);
    d += c[b];
  }
  
  printf("%d\n", d);
  
  free(c);
  
  return 0;
}