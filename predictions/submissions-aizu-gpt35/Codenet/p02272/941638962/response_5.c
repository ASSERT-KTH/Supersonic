#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000001

void mergesort(int *, int, int);
void merge(int *, int, int, int);
long long count = 0, n;
int *Left, *Right;

int main(void) {
  int i;
  int *S = NULL;
  scanf("%lld", &n);
  S = (int*) malloc(n * sizeof(int));
  Left = (int*) malloc((n/2 + 2) * sizeof(int));
  Right = (int*) malloc((n/2 + 2) * sizeof(int));
  for (i = 0; i < n; i++)
    scanf("%d", &S[i]);
  mergesort(S, 0, n);
  for (i = 0; i < n; i++) {
    printf("%d", S[i]);
    if (i != n - 1)
      printf(" ");
  }
  printf("\n%lld\n", count);
  free(S);
  free(Left);
  free(Right);
  return EXIT_SUCCESS;
}

void mergesort(int *S, int left, int right) {
  int mid;
  if (left + 1 < right) {
    mid = (left + right) / 2;
    mergesort(S, left, mid);
    mergesort(S, mid, right);
    merge(S, left, mid, right);
  }
}

void merge(int *S, int left, int mid, int right) {
  int i, j, k;
  int n1 = mid - left;
  int n2 = right - mid;
  for (i = 0; i < n1; i++)
    Left[i] = S[left + i];
  for (i = 0; i < n2; i++)
    Right[i] = S[mid + i];
  Left[n1] = MAX;
  Right[n2] = MAX;
  i = 0;
  j = 0;
  for (k = left; k < right; k++) {
    if (Left[j] > Right[i])
      S[k] = Right[i++];
    else {
      S[k] = Left[j++];
      count += n2 - i;
    }
  }
}