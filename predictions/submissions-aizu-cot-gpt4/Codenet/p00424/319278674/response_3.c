#include <stdio.h>
#include <string.h>

int arrSize = 999;
char n, t[999];

int main() {
  while (scanf("%d", &n) == 1) {
    memset(t, 0, sizeof(t));
    for (int i = 0; i < n; i++)
      scanf(" %c %c", &n, &t[i]);

    for (int i = 0; i < n; i++) 
      printf("%c", !t[i] * i + t[i]);
      
    printf("\n");
  }
  return 0;
}