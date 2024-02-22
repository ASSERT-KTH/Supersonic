#include <stdio.h>
#include <string.h>

char R1[99], R2[99];
char *R = R1;
int i = 0, h = 0, b = 0;
char buffer[10];

int main() {
  while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
    for (int j = 0; j < sizeof(buffer) && buffer[j] != '\0'; ++j) {
      char c = buffer[j];
      b += !!R[c], h += !(R[c] ^= 1 << i % 5);
      if (++i > 9) {
        printf("%d %d\n", h, b - h);
        i = h = b = 0;
        R = (R == R1) ? R2 : R1;
        memset(R, 0, sizeof(R1));
      }
    }
  }
  return 0;
}