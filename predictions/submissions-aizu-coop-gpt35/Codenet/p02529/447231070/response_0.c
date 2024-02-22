#include <stdio.h>
#include <stdlib.h>

int main() {
  int b, d = 0;
  int* c;
  int i;

  scanf("%d", &b);
  c = (int*)malloc(b * sizeof(int)); // Dynamically allocate memory for the array

  for (i = 0; i < b; i++) {
    scanf("%d", &c[i]); // Read numbers directly into the array
    d += c[i]; // Calculate the sum
  }

  printf("%d\n", d);

  free(c); // Free the dynamically allocated memory

  return 0;
}