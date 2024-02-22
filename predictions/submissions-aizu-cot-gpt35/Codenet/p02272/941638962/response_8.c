#include <stdio.h>
#define MAX 1000000001

void mergesort(int *, int);
void merge(int *, int, int, int);

int main(void) {
  int S[500000];
  int n, i;

  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &S[i]);

  mergesort(S, n);

  for (i = 0; i < n; i++) {
    printf("%d", S[i]);
    if (i != n - 1)
      printf(" ");
  }
  printf("\n");

  return 0;
}

void mergesort(int *S, int n) {
  int subarray_size, left;

  for (subarray_size = 1; subarray_size < n; subarray_size *= 2) {
    for (left = 0; left < n - subarray_size; left += 2 * subarray_size) {
      int mid = left + subarray_size - 1;
      int right = left + 2 * subarray_size - 1;
      if (right >= n)
        right = n - 1;
      merge(S, left, mid, right);
    }
  }
}

void merge(int *S, int left, int mid, int right) {
  int merged[right - left + 1];
  int i = left;
  int j = mid + 1;
  int k = 0;

  while (i <= mid && j <= right) {
    if (S[i] <= S[j])
      merged[k++] = S[i++];
    else
      merged[k++] = S[j++];
  }

  while (i <= mid)
    merged[k++] = S[i++];

  while (j <= right)
    merged[k++] = S[j++];

  for (i = left, k = 0; i <= right; i++, k++)
    S[i] = merged[k];
}