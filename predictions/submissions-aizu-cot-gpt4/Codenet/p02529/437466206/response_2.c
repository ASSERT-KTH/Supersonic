#include <stdio.h>
#include <stdlib.h>

// Function to compare two elements. It is used in qsort
int compare(const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}

// Function to search y in arr[l..r] using binary search
int binary_search(int arr[], int l, int r, int y) {
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (arr[m] == y)
      return m;
    if (arr[m] < y)
      l = m + 1;
    else
      r = m - 1;
  }
  return -1;
}

int main() {
  int i, n, q, t, C = 0, S[100], T[100];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &S[i]);
  }
  // Sort the array S
  qsort(S, n, sizeof(int), compare);
  
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &T[i]);
  }
  for (i = 0; i < q; i++) {
    if (binary_search(S, 0, n-1, T[i]) != -1) {
      C++;
    }
  }
  printf("%d\n", C);
  return 0;
}