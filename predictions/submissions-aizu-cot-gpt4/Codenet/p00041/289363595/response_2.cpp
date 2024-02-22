#include <stdio.h>
int main() {
  register int a[4];
  while (1) {
    for (register int i = 0; i < 4; ++i) {
      scanf("%d", &a[i]);
    }
    if (a[0] == 0) {
      break;
    }