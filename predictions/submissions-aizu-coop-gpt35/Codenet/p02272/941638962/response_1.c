#include <stdio.h>
#include <stdlib.h>

void mergesort(int *, int, int);
void merge(int *, int, int, int);

int n;
int *Left, *Right;

int main(void) {
  scanf("%d", &n);

  int *S = (int *)malloc(sizeof(int) * n);
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

  Left = (int *)malloc(sizeof(int) * n1);
  Right = (int *)malloc(sizeof(int) * n2);

  for (int i = 0; i < n1; i++)
    Left[i] = S[left + i];
  for (int i = 0; i < n2; i++)
    Right[i] = S[mid + i];

  int i = 0;
  int j = 0;
  int k = left;
  int inversions = 0;

  while (k < right) {
    if (Left[j] > Right[i]) {
      S[k++] = Right[i++];
      inversions += n1 - j;
    } else {
      S[k++] = Left[j++];
    }
  }

  for (; j < n1; j++)
    S[k++] = Left[j];
  for (; i < n2; i++)
    S[k++] = Right[i];

  free(Left);
  free(Right);
}
