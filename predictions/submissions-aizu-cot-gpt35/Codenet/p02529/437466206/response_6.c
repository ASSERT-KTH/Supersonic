#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, n, q;
  scanf("%d", &n);
  int *S = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; i++) {
    scanf("%d", &S[i]);
  }
  scanf("%d", &q);
  int *T = (int *)malloc(q * sizeof(int));
  for (i = 0; i < q; i++) {
    scanf("%d", &T[i]);
  }
  int C = 0;
  for (i = 0; i < n; i++) {
    int found = binarySearch(T, q, S[i]);
    if (found != -1) {
      C++;
    }
  }
  printf("%d\n", C);
  free(S);
  free(T);
  return 0;
}

int binarySearch(int arr[], int size, int key) {
  int left = 0, right = size - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == key) {
      return mid;
    }
    if (arr[mid] < key) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}