#include <stdio.h>

#define SIZE 999

int a, b, d, c[SIZE] = {0};

int main() {
  if (scanf("%d", &a) != 1) return 1; // check the result of scanf
  for (; a > 0 && a <= SIZE; a--) {
    if (scanf("%d", &b) != 1) return 1; // check the result of scanf
    if (b >= 0 && b < SIZE) c[b] = 1; // check if b is within the expected range
  }
  if (scanf("%d", &a) != 1) return 1; // check the result of scanf
  for (; a > 0 && a <= SIZE; a--) {
    if (scanf("%d", &b) != 1) return 1; // check the result of scanf
    if (b >= 0 && b < SIZE) d += c[b]; // check if b is within the expected range
  }
  printf("%d\n", d);
  return 0;
}