#include <stdio.h>

int main(int argc, char *argv[]) {
  int x = atoi(argv[1]);
  int result = x * x * x;
  printf("%d\n", result);
}