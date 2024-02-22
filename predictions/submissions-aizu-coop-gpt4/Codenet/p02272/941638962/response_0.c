#include <stdio.h>
#define MAX 1000000001

void mergesort(int *, int, int, int*);
void merge(int *, int, int, int, int*);

int main(void) {
  int S[500000];
  int count = 0, n, i;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &S[i]);
  mergesort(S, 0, n, &count);
  for (i = 0; i < n; i++) {
    printf("%d", S[i]);
    if (i != n - 1)
      printf(" ");
  }
  printf("\n%d\n", count);
  return 0;
}

void mergesort(int *S, int left, int right, int* count) {
  int mid;
  if (left + 1 < right) {
    mid = (left + right) / 2;
    mergesort(S, left, mid, count);
    mergesort(S, mid, right, count);
    merge(S, left, mid, right, count);
  }
}

void merge(int *S, int left, int mid, int right, int* count) {
  int n1 = mid - left;
  int n2 = right - mid;
  int Left[250001], Right[250001];
  int i, j, k;
  for (i = 0; i < n1; i++)
    Left[i] = S[left + i];
  for (i = 0; i < n2; i++)
    Right[i] = S[mid + i];
  Left[n1] = MAX;
  Right[n2] = MAX;
  i = 0;
  j = 0;
  for (k = left; k < right; k++) {
    if (Left[j] > Right[i]) {
      S[k] = Right[i++];
    } else {
      S[k] = Left[j++];
    }
    *count += 1;
  }
}