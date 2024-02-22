#include <stdio.h>

int main(void) {
  printf("%d", (scanf("%d", &(int){0})) * (scanf("%d", &(int){0})) * (scanf("%d", &(int){0})));
  return 0;
}