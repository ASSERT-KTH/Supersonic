#include <stdio.h>
#include <stdlib.h>

void mergesort(int *, int, int, int*);
void merge(int *, int, int, int, int*);

int main(void) {
  int n;
  scanf("%d", &n);

  int *S = (int*) malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    scanf("%d", &S[i]);

  int count = 0;
  mergesort(S, 0, n, &count);

  for (int i = 0; i < n; i++) {
    printf("%d", S[i]);
    if (i != n - 1)
      printf(" ");
  }

  printf("\n%d\n", count);
  free(S);
  return 0;
}

void mergesort(int *S, int left, int right, int *count) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergesort(S, left, mid, count);
    mergesort(S, mid, right, count);
    merge(S, left, mid, right, count);
  }
}

void merge(int *S, int left, int mid, int right, int *count) {
  int n1 = mid - left;
  int n2 = right - mid;

  int *Left = (int*) malloc((n1 + 1) * sizeof(int));
  int *Right = (int*) malloc((n2 + 1) * sizeof(int));

  for (int i = 0; i < n1; i++)
    Left[i] = S[left + i];
  for (int i = 0; i < n2; i++)
    Right[i] = S[mid + i];

  Left[n1] = Right[n2] = 1000000001;

  int i = 0, j = 0;
  for(int k = left; k < right; k++) {
    if (Left[i] <= Right[j])
      S[k] = Left[i++];
    else
      S[k] = Right[j++];
  }

  *count += right - left;

  free(Left);
  free(Right);
}