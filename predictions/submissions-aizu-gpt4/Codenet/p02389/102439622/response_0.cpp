#include <stdio.h>
int main() {
  int a, b;
  if(scanf("%d %d", &a, &b)) {
    printf("%d %d\n", a * b, (a + b) << 1);
  }
}