#include <stdio.h>

void mergesort(int *, int, int);
void merge(int *, int, int, int);

int main(void) {
  int n;
  scanf("%d", &n);
  int S[n];
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
  if (left < right - 1) {
    int mid = (left + right) / 2;
    mergesort(S, left, mid);
    mergesort(S, mid, right);
    merge(S, left, mid, right);
  }
}

void merge(int *S, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1], R[n2];

  for (int i = 0; i < n1; i++)
    L[i] = S[left + i];
  for (int i = 0; i < n2; i++)
    R[i] = S[mid + i];

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j])
      S[k++] = L[i++];
    else
      S[k++] = R[j++];
  }

  while (i < n1)
    S[k++] = L[i++];
  while (j < n2)
    S[k++] = R[j++];
}