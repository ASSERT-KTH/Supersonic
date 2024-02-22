#include <stdio.h>
#include <stdlib.h>

void mergesort(int *, int, int);
int* merge(int *, int, int, int);

int main(void) {
  int n;
  scanf("%d", &n);

  int *S = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    scanf("%d", &S[i]);

  mergesort(S, 0, n);

  for (int i = 0; i < n; i++) {
    printf("%d", S[i]);
    if (i != n - 1)
      printf(" ");
  }
  printf("\n");

  free(S);
  return 0;
}

void mergesort(int *S, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergesort(S, left, mid);
    mergesort(S, mid, right);
    int* merged = merge(S, left, mid, right);
    for (int i = left; i < right; i++)
      S[i] = merged[i - left];
    free(merged);
  }
}

int* merge(int *S, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  int* Left = malloc((n1 + 1) * sizeof(int));
  int* Right = malloc((n2 + 1) * sizeof(int));

  for (int i = 0; i < n1; i++)
    Left[i] = S[left + i];
  for (int i = 0; i < n2; i++)
    Right[i] = S[mid + i];

  Left[n1] = Right[n2] = INT_MAX;

  int i = 0, j = 0, k = left;
  int* merged = malloc((right - left) * sizeof(int));

  for (; k < right; k++) {
    if (Left[j] <= Right[i])
      merged[k - left] = Left[j++];
    else {
      merged[k - left] = Right[i++];
      // Increment count for the number of inversions
      count += n1 - j;
    }
  }

  free(Left);
  free(Right);

  return merged;
}