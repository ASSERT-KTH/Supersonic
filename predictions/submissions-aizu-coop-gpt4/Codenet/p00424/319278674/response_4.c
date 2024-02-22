#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  int n;
  
  while (scanf("%d", &n) == 1) {
    char *t = calloc(n, sizeof(char));
  
    for (int i = 0; i < n; i++)
      scanf(" %c", &t[i]);
  
    printf("%s\n", t);
  
    free(t);
  
    int m;
    scanf("%d", &m);
    char *s = calloc(m, sizeof(char));
  
    for (int i = 0; i < m; i++)
      scanf(" %c", &s[i]);
  
    printf("%s\n", s);
  
    free(s);
  }
  
  return 0;
}