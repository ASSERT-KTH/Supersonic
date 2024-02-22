#include <stdio.h>
#define MAX 1000000001

void mergesort(int *S, int left, int right, int *count) {
  int mid;
  if (left + 1 < right) {
    mid = left + ((right - left) / 2);
    mergesort(S, left, mid, count);
    mergesort(S, mid, right, count);
    merge(S, left, mid, right, count);
  }
}

void merge(int *S, int left, int mid, int right, int *count) {
  int i, j, k, n1, n2;
  int Left[250001], Right[250001];
  
  n1 = mid - left;
  n2 = right - mid;
  for (i = 0; i < n1; i++)
    Left[i] = S[left + i];
  for (i = 0; i < n2; i++)
    Right[i] = S[mid + i];
  Left[n1] = MAX;
  Right[n2] = MAX;
  i = 0;
  j = 0;
  k = left;
  while (k < right) {
    if (Left[j] > Right[i])
      S[k++] = Right[i++];
    else
      S[k++] = Left[j++];
  }
  *count += right - left;
}

int main(void) {
  int S[500000];
  int n, count = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &S[i]);
  mergesort(S, 0, n, &count);
  for (int i = 0; i < n; i++) {
    printf("%d", S[i]);
    if (i != n - 1)
      printf(" ");
  }
  printf("\n%d\n", count);
  return 0;
}