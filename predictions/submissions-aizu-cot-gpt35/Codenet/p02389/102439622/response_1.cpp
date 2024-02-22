#include <stdio.h>
int main() {
  char input[255];
  fgets(input, sizeof(input), stdin);
  int a, b;
  sscanf(input, "%d %d", &a, &b);

  int area = a * b;
  int c = a * 2 + b * 2;
  printf("%d %d\n", area, c);
}