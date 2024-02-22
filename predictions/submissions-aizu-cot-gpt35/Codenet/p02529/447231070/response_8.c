#include <stdio.h>

int b, d, c[1000];

int main() {
  scanf("%d", &b);
  for (int i = 0; i < b; i++) {
    int input;
    scanf("%d", &input);
    d += input;
    c[input]++;
  }
  
  printf("%d\n", d);
  return 0;
}