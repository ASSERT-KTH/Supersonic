#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, n, q, *arr, val, C = 0;
  scanf("%d", &n);
  arr = (int*) malloc(n * sizeof(int));
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  scanf("%d", &q);
  
  // Using a hash set to store the values of S
  int *hashSet = (int*) calloc(1000001, sizeof(int)); // Assuming the maximum value of S[i] is 10^6
  for (i = 0; i < n; i++) {
    hashSet[arr[i]] = 1;
  }
  
  for (i = 0; i < q; i++) {
    scanf("%d", &val);
    // Checking if the value exists in S in constant time
    if (hashSet[val] == 1) {
      C++;
    }
  }
  
  printf("%d\n", C);
  
  free(arr);
  free(hashSet);
  
  return 0;
}