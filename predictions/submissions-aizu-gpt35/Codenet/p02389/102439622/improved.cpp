#include <stdio.h>
int main(void) {
  int a, b;
  scanf("%d %d", &a, &b);
  int s = a * b;
  int mawari = a * 2 + b * 2;
  printf("%d %d\n", s, mawari);
  return 0;
}
