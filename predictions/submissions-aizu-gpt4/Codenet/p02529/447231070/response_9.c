#include <stdio.h>
#define MAX 999
int c[MAX] = {0};
int main() {
  int a, b;
  scanf("%d", &a);
  while (a--) {
    scanf("%d", &b);
    c[b] = 1;
  }
  int d = 0;
  scanf("%d", &a);
  while (a--) {
    scanf("%d", &b);
    d += c[b];
  }
  printf("%d\n", d);
  return 0;
}