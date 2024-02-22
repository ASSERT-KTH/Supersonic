#include <stdio.h>
#include <string.h>

int main() {
  int n, i, t[999];
  char input[4000], *p;
  
  while (fgets(input, sizeof(input), stdin) && sscanf(input, "%d", &n)==1) {
    memset(t, 0, n * sizeof(int));
    
    fgets(input, sizeof(input), stdin);
    p = input;
    
    for (i=0; i<n; i++)
      p = strchr(p, ' ') + 1, t[i] = *p++;
      
    fgets(input, sizeof(input), stdin);
    p = input;
    
    for (i=0; i<n; i++)
      p = strchr(p, ' ') + 1, putchar(!t[i] * (*p++) + t[i]), putchar('\n');
  }
  
  return 0;
}