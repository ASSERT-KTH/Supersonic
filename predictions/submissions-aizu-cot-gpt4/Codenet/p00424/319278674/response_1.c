#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int n = 0;
  int* t = NULL;
  int i = 0;

  while(scanf("%d", &n), n) {
    t = (int*)realloc(t, n * sizeof(int));
    memset(t, 0, n * sizeof(int));
    
    for (i = 0; i < n; i++)
      scanf(" %c %c", &i, &t[i]);
    
    for(scanf("%d", &n); n--; putchar(!t[i] * i + (int)t[i]))
      scanf(" %c", &i);
    putchar('\n');
  }

  free(t);
  return 0;
}