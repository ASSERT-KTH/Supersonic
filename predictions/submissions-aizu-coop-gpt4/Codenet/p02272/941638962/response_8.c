#include <stdio.h>

void mergesort(int *, int, int);
void merge(int *, int, int, int);

int main(void) {
  int S[500000];
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &S[i]);
  mergesort(S, 0, n);
  for (int i = 0; i < n; i++) {
    printf("%d", S[i]);
    if (i != n - 1)
      printf(" ");
  }
  printf("\n");
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

void merge(int *S, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  int i = 0;
  int j = 0;
  int k = left;
  while (i < n1 && j < n2) {
    if (S[left + i] <= S[mid + j])
      S[k++] = S[left + i++];
    else
      S[k++] = S[mid + j++];
  }
  while (i < n1)
    S[k++] = S[left + i++];
  while (j < n2)
    S[k++] = S[mid + j++];
}