#include <stdio.h>

int main() {
  int a, b, d = 0, c[1000] = {0}, input[2000];
  
  scanf("%d", &a);
  for (int i = 0; i < a; i++) {
    scanf("%d", &b);
    input[i] = b;
    c[b] = 1;
  }
  
  scanf("%d", &a);
  for (int i = 0; i < a; i++) {
    scanf("%d", &b);
    input[i + a] = b;
  }

  for (int i = 0; i < 2 * a; i++) {
    d += c[input[i]];
  }

  printf("%d\n", d);
  return 0;
}