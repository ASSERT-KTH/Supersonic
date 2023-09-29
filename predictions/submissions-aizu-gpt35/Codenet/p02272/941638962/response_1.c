#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000001

void mergesort(int *, int, int);
void merge(int *, int, int, int);

int count = 0, n;
int *Left, *Right, *S;

int main(void) {
  scanf("%d", &n);
  S = (int*)malloc(n * sizeof(int));
  Left = (int*)malloc(((n/2) + 1) * sizeof(int));
  Right = (int*)malloc(((n/2) + 1) * sizeof(int));

  for (int i = 0; i < n; i++)
    scanf("%d", &S[i]);

  mergesort(S, 0, n);

  for (int i = 0; i < n; i++) {
    printf("%d", S[i]);
    if (i != n - 1)
      printf(" ");
  }
  printf("\n%d\n", count);

  free(S);
  free(Left);
  free(Right);

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
}