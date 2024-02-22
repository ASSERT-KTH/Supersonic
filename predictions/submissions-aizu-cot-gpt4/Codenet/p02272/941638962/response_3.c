#include <stdio.h>
#define MAX 1000000001
void mergesort(int *, int, int);
void merge(int *, const int, const int, const int);
int count = 0, n;
int main(void) {
  int S[500000];
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &S[i]);
  mergesort(S, 0, n);
  printf("%d", S[0]);
  for (int i = 1; i < n; i++) {
    printf(" %d", S[i]);
  }
  printf("\n%d\n", count);
  return 0;
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
void merge(int *S, const int left, const int mid, const int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  int Left[n1+1], Right[n2+1];
  for (int i = 0; i < n1; i++)
    Left[i] = S[left + i];
  for (int i = 0; i < n2; i++)
    Right[i] = S[mid + i];
  Left[n1] = MAX;
  Right[n2] = MAX;
  int i = 0;
  int j = 0;
  int k = left;
  while (k < right) {
    if (Left[j] > Right[i])
      S[k++] = Right[i++];
    else
      S[k++] = Left[j++];
  }
  count += right - left;
}