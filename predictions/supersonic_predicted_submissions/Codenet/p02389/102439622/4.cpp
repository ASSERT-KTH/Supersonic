#include <stdio.h>
int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int area = a * b;
  printf("%d %d\n", area, 2 * a + 2 * b);
}
