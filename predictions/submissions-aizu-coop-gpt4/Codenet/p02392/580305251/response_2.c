#include <stdio.h>
int main(void) {
  int a, b, c;
  if (scanf("%d %d %d", &a, &b, &c) == 3 && 0 <= a && a <= 100 && 0 <= b && b <= 100 && 0 <= c && c <= 100) {
    printf((a < b && b < c) ? "Yes\n" : "No\n");
  } else {
    printf("Invalid input\n");
  }
  return (0);
}