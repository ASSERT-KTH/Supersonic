#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000001

void mergesort(int *, int, int);
void merge(int *, int, int, int);

int count = 0, n;

int main(void) {
  int S[500000];
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &S[i]);
  mergesort(S, 0, n);
  for (int i = 0; i < n; i++) {
    printf("%d", S[i]);
    if (i != n - 1)
      putchar(' ');
  }
  putchar('\n');
  printf("%d\n", count);
  return 0;
}

void mergesort(int *S, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergesort(S, left, mid);
    mergesort(S, mid, right);
    merge(S, left, mid, right);
  }
}

void merge(int *S, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  int *Left = malloc((n1 + 1) * sizeof(int));
  int *Right = malloc((n2 + 1) * sizeof(int));
  for (int i = 0; i < n1; i++)
    Left[i] = S[left + i];
  for (int i = 0; i < n2; i++)
    Right[i] = S[mid + i];
  Left[n1] = MAX;
  Right[n2] = MAX;
  int i = 0, j = 0, k = left;
  while (k < right) {
    if (Left[j] > Right[i])
      S[k++] = Right[i++];
    else
      S[k++] = Left[j++];
  }
  count += right - left;
  free(Left);
  free(Right);
}