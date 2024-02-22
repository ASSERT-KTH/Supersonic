#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Invalid number of arguments\n");
    return 1;
  }

  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  int c = atoi(argv[3]);

  if (a < b && b < c) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}