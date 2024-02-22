#include <stdio.h>
#include <stdlib.h>

int main() {
  int a, b, d = 0;
  
  // read the size of the first set of numbers
  scanf("%d", &a);
  
  // dynamically allocate the bitset array
  int* c = (int*)calloc(a, sizeof(int));
  
  // read the first set of numbers and mark them in the bitset
  for (int i = 0; i < a; ++i) {
    scanf("%d", &b);
    c[b - 1] = 1;
  }
  
  // read the size of the second set of numbers
  scanf("%d", &a);
  
  // read the second set of numbers and count the marked numbers
  for (int i = 0; i < a; ++i) {
    scanf("%d", &b);
    d += c[b - 1];
  }
  
  printf("%d\n", d);
  
  // free the dynamically allocated memory
  free(c);
  
  return 0;
}