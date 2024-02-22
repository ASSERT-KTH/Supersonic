#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000001

void mergesort(int *, int, int, int*);
void merge(int *, int, int, int, int*);

int main(void) {
  int n, count = 0;
  scanf("%d", &n);
  int *S = (int*)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &S[i]);
  }
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

void mergesort(int *S, int left, int right, int* count) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergesort(S, left, mid, count);
    mergesort(S, mid, right, count);
    merge(S, left, mid, right, count);
  }
}

void merge(int *S, int left, int mid, int right, int* count) {
  int n1 = mid - left;
  int n2 = right - mid;
  int *Left = (int*)malloc(sizeof(int) * (n1 + 1));
  int *Right = (int*)malloc(sizeof(int) * (n2 + 1));
  for (int i = 0; i < n1; i++)
    Left[i] = S[left + i];
  for (int i = 0; i < n2; i++)
    Right[i] = S[mid + i];
  Left[n1] = MAX;
  Right[n2] = MAX;
  int i = 0;
  int j = 0;
  for (int k = left; k < right; k++) {
    if (Left[j] > Right[i])
      S[k] = Right[i++];
    else
      S[k] = Left[j++];
  }
  *count += right - left;
  free(Left);
  free(Right);
}