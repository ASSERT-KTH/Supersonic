#include <cstdio>

int main() {
  int a;
  int b;
  scanf("%d %d", &a, &b);

  int result = a * 2 + b * 2;
  printf("%d %d\n", a * b, result);

  return 0;
}