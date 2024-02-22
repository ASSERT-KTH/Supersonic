#include <stdio.h>
#include <stdlib.h> // for malloc and free

int main() {
  int a, b, d;
  int* c; // pointer to dynamically allocated memory
  int max_input = 0;

  scanf("%d", &b);
  for (a = b; a > 0; a--) {
    scanf("%d", &b);
    if (b > max_input) {
      max_input = b;
    }
  }

  // dynamically allocate memory for c based on the maximum input value
  c = (int*) malloc((max_input + 1) * sizeof(int));

  // initialize all elements of c to 0
  for (int i = 0; i <= max_input; i++) {
    c[i] = 0;
  }

  // count the frequency of each input number
  for (a = b; a > 0; a--) {
    scanf("%d", &b);
    c[b]++;
  }

  // calculate the sum of frequencies
  d = 0;
  for (int i = 0; i <= max_input; i++) {
    d += c[i];
  }

  printf("%d\n", d);

  // free the dynamically allocated memory
  free(c);

  return 0;
}