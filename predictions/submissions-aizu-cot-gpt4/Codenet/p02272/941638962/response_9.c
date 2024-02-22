#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000001

void mergesort(int *, int, int, int&, int*, int*);
void merge(int *, int, int, int, int&, int*, int*);

int main(void) {
  int n;
  scanf("%d", &n);
  int* S = (int*)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    scanf("%d", &S[i]);
  int count = 0;
  int* Left = (int*)malloc((n/2 + 1) * sizeof(int));
  int* Right = (int*)malloc((n/2 + 1) * sizeof(int));
  mergesort(S, 0, n, count, Left, Right);
  for (int i = 0; i < n; i++) {
    printf(i != n - 1 ? "%d " : "%d\n", S[i]);
  }
  printf("%d\n", count);
  free(S);
  free(Left);
  free(Right);
  return 0;
}

void mergesort(int *S, int left, int right, int& count, int* Left, int* Right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergesort(S, left, mid, count, Left, Right);
    mergesort(S, mid, right, count, Left, Right);
    merge(S, left, mid, right, count, Left, Right);
  }
}

void merge(int *S, int left, int mid, int right, int& count, int* Left, int* Right) {
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