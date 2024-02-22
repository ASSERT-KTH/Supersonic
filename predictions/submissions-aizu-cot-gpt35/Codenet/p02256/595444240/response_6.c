#include <stdio.h>

int main(int argc, char *argv[]) {
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  int c;

  do {
    c = a % b;
    a = b;
    b = c;
  } while (c > 0);

  printf("%d\n", a);
}