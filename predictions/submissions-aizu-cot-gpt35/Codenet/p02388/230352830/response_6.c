#include <stdio.h>

int main(void) {
  char input[10]; // Assuming the input number has at most 10 digits
  fgets(input, sizeof(input), stdin);
  int x;
  sscanf(input, "%d", &x);
  printf("%d\n", x * x * x);
  return 0;
}