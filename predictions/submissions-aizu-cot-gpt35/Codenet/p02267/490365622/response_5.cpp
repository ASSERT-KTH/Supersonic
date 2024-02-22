#include <stdio.h>

int main() {
  int n, q, num, cnt = 0;
  scanf("%d", &n);
  
  // Create a hash set to store the elements of S
  int S[10001] = {0};
  
  for (int i = 0; i < n; i++) {
    scanf("%d", &num);
    S[num] = 1; // Mark the element as present in S
  }
  
  scanf("%d", &q);
  
  for (int i = 0; i < q; i++) {
    scanf("%d", &num);
    if (S[num] == 1) {
      cnt++; // Increment the count if the element exists in S
    }
  }
  
  printf("%d\n", cnt);
  
  return 0;
}