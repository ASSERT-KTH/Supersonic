#include <stdio.h>
#define MAX 1000000001

void mergesort(int *, int, int);
void merge(int, int, int);
int n, S[500000], Left[250001], Right[250001];
int count = 0;

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &S[i]);
  mergesort(S, 0, n);
  for (int i = 0; i < n; i++) {
    printf("%d", S[i]);
    if (i != n - 1)
      printf(" ");
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
    merge(left, mid, right);
  }
}

void merge(int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  for (int i = 0; i < n1; i++)
    Left[i] = S[left + i];
  for (int i = 0; i < n2; i++)
    Right[i] = S[mid + i];
  int i = 0, j = 0, k = left;
  while (k < right) {
    if (j >= n1 || (i < n2 && Left[j] > Right[i]))
      S[k++] = Right[i++];
    else
      S[k++] = Left[j++];
  }
  count += right - left;
}