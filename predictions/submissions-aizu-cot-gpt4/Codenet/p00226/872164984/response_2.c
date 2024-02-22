#include<stdio.h>

int R[99], i, h, b;

void process(int c) {
  b += !!R[c];
  h += !(R[c] = (i < 5) ? 1 : 0);
  if (++i > 9) {
    printf("%d %d\n", h, b - h);
    i = h = b = 0;
  }
}

int main() {
  int c;
  while ((c = getchar()) != EOF)
    process(c);
  return 0;
}