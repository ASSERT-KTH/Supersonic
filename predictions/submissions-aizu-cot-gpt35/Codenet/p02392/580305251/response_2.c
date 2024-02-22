#include <stdio.h>

int main(void) {
  int a, b, c;
  char input[100];

  fgets(input, sizeof(input), stdin);
  sscanf(input, "%d %d %d", &a, &b, &c);

  printf("%s\n", (a < b && b < c) ? "Yes" : "No");

  return 0;
}