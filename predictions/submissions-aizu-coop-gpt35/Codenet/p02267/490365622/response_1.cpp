#include <stdio.h>
#include <stdlib.h>

// Comparison function for quicksort
int compare(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
}

// Binary search algorithm
int binarySearch(int arr[], int size, int target) {
  int left = 0;
  int right = size - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (arr[mid] == target) {
      return 1;
    }
    if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return 0;
}

int main() {
  int n, *S, q, *T, i, cnt = 0;

  scanf("%d", &n);
  S = (int *)malloc(sizeof(int) * n);
  for (i = 0; i < n; i++)
    scanf("%d", &S[i]);

  scanf("%d", &q);
  T = (int *)malloc(sizeof(int) * q);
  for (i = 0; i < q; i++)
    scanf("%d", &T[i]);

  // Sort array S
  qsort(S, n, sizeof(int), compare);

  // Perform binary search for each element of T
  for (i = 0; i < q; i++)
    if (binarySearch(S, n, T[i])) {
      cnt++;
    }

  printf("%d\n", cnt);

  // Free dynamically allocated memory
  free(S);
  free(T);

  return 0;
}