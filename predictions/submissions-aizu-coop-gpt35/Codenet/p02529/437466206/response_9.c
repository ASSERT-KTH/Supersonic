#include <stdio.h>
#include <stdbool.h>

bool isValidInput(int result) {
  // Check if scanf() successfully read one integer
  return result == 1;
}

int main() {
  int i, k, n, q, t, C = 0, S[100], T[100];
  
  // Input validation
  if (!isValidInput(scanf("%d", &n))) {
    printf("Invalid input for n\n");
    return 1;
  }
  
  for (i = 0; i < n; i++) {
    if (!isValidInput(scanf("%d", &S[i]))) {
      printf("Invalid input for S[%d]\n", i);
      return 1;
    }
  }
  
  if (!isValidInput(scanf("%d", &q))) {
    printf("Invalid input for q\n");
    return 1;
  }
  
  for (i = 0; i < q; i++) {
    if (!isValidInput(scanf("%d", &T[i]))) {
      printf("Invalid input for T[%d]\n", i);
      return 1;
    }
  }
  
  // Rest of the code
  
  return 0;
}