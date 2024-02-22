#include <stdio.h>
#define MAX 1000000001

void mergesort(int *, int, int);
void merge(int *, int *, int, int, int);

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
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergesort(S, left, mid);
    mergesort(S, mid, right);

    int temp[right - left];
    merge(S, temp, left, mid, right);
  }
}

void merge(int *S, int *temp, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;

  int *Left = &S[left];
  int *Right = &S[mid];

  int i = 0;
  int j = 0;
  int k = 0;

  while (i < n1 && j < n2) {
    if (Left[i] > Right[j])
      temp[k++] = Right[j++];
    else
      temp[k++] = Left[i++];
  }

  while (i < n1)
    temp[k++] = Left[i++];
  while (j < n2)
    temp[k++] = Right[j++];

  for (int i = 0; i < k; i++)
    S[left + i] = temp[i];
}