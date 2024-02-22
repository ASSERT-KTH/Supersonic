#include <stdio.h>

int main(int argc, char *argv[]) {
  int a, b, c;
  
  a = atoi(argv[1]);
  b = atoi(argv[2]);
  c = atoi(argv[3]);

  if (a < b && b < c) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}