#include <stdio.h>
#include <string.h>
#include <unistd.h>

const int ARRAY_SIZE = 99;
const int MODULUS = 5;
const int PRINTF_BUFFER_SIZE = 232;

int R[ARRAY_SIZE];
int i, h, b;

bool isCharacterInArray(int c) {
  return R[c];
}

bool isCharacterNotInArray(int c) {
  return !R[c];
}

void updateArray(int c) {
  R[c] ^= 1 << i % MODULUS;
}

int main() {
  int c;
  for (; read(0, &c, 1) == 1;
       ++i > 9 && memset(R, i = h = b = printf("%d %d\n", h, b - h) != 0, sizeof(R))) {
    b += isCharacterInArray(c);
    h += isCharacterNotInArray(c);
    updateArray(c);
  }
  return 0;
}