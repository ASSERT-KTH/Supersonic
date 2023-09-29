#include <stdio.h>
int main(void) {
  int a = 0, b = 0, c = 0;
  scanf("%d %d %d", &a, &b, &c);
  printf((a < b && b < c) ? "Yes\n" : "No\n");
  return 0;
}