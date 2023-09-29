#include <stdio.h>
int main() {
  int i, j, tab[10][10];
  for (i = 1; i < 10; i++) {
    for (j = 1; j < 10; j++) {
      tab[i][j] = i * j;
    }
  }
  for (i = 1; i < 10; i++) {
    for (j = 1; j < 10; j++) {
      printf("%dx%d=%d\n", i, j, tab[i][j]);
    }
  }
  return 0;
}