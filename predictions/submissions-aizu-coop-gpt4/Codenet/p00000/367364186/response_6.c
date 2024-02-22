#include <stdio.h>

int main() {
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j+=8) {
      int res1 = i*j;
      printf("%dx%d=%d\n", i, j, res1);

      int res2 = i*(j+1);
      printf("%dx%d=%d\n", i, j+1, res2);

      int res3 = i*(j+2);
      printf("%dx%d=%d\n", i, j+2, res3);

      int res4 = i*(j+3);
      printf("%dx%d=%d\n", i, j+3, res4);

      int res5 = i*(j+4);
      printf("%dx%d=%d\n", i, j+4, res5);

      int res6 = i*(j+5);
      printf("%dx%d=%d\n", i, j+5, res6);

      int res7 = i*(j+6);
      printf("%dx%d=%d\n", i, j+6, res7);

      int res8 = i*(j+7);
      printf("%dx%d=%d\n", i, j+7, res8);
    }
  }
  return 0;
}