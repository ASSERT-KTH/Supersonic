#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, *c, b, sum = 0;
  
  scanf("%d", &n);
  c = (int*)calloc(n + 1, sizeof(int)); // Dynamically allocate memory for c
  
  for (int i = 0; i < n; i++) {
    scanf("%d", &b);
    c[b]++; // Increment count for each occurrence
  }
  
  for (int i = 0; i < n; i++) {
    scanf("%d", &b);
    sum += c[b]; // Accumulate the count for each input value
  }
  
  printf("%d\n", sum);
  
  free(c); // Free the dynamically allocated memory
  
  return 0;
}