#include <stdio.h>
#include <string.h>

#define MAX_SIZE 999

int n, t[MAX_SIZE];

int main() {
  int i;
  while(scanf("%d", &n) == 1 && n != 0) { 
    memset(t, 0, MAX_SIZE * sizeof(int));
    for (i = 0; i < n; i++) {
      scanf(" %c", &t[i]);
    }
    if(scanf("%d", &n) == 1) {
      for (i = 0; i < n; i++) {
        char temp;
        scanf(" %c", &temp);
        putchar(!t[temp] * temp + t[temp]);
      }
    }
    printf("\n");
  }
  return 0;
}