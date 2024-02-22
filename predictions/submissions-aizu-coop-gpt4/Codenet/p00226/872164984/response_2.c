#include <stdio.h>
#include <string.h>

int R[99];
int i, h, b;
char buffer[4096];

int main() {
  int n, c;
  while ((n = read(0, buffer, sizeof(buffer))) > 0) {
    for (int j = 0; j < n; ++j) {
      c = buffer[j];
      if (R[c] & 1 << i % 5) {
        --h;
      } else {
        ++h;
      }
      R[c] ^= 1 << i % 5;
      if (R[c] & 1 << i % 5) {
        ++b;
      } else {
        --b;
      }
      if (++i > 9) {
        printf("%d %d\n", h, b - h);
        for (int k = 0; k < 99; ++k) {
          if (R[k]) {
            R[k] = 0;
          }
        }
        i = h = b = 0;
      }
    }
  }
  return 0;
}