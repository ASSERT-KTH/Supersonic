#include <stdio.h>

int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  printf("%s", (c > a) ? "Yes" : "No");
  return 0;
}