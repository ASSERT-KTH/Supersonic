#include <stdio.h>

int a[4];

int main() {
  while (1) {
    for (int i = 0; i < 4; ++i) {
      scanf("%d", &a[i]);
      if (i == 0 && a[0] == 0) {
        return 0;
      }
    }