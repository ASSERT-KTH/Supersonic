#include <stdio.h>

int main() {
  while (1) {
    int a[4];
    for (int i = 0; i < 4; ++i) {
      scanf("%d", &a[i]);
    }
    if (a[0] == 0) {
      break;
    }