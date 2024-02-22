#include <stdio.h>

#define MAX 1000000001

void mergesort(int *, int, int);
void merge(int *, int, int, int);

int main(void) {
  int n;
  scanf("%d", &n);

  int S[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &S[i]);
  }

  mergesort(S, 0, n);

  for (int i = 0; i < n; i++) {
    printf("%d", S[i]);
    if (i != n - 1) {
      printf(" ");
    }
  }

  printf("\n");

  return 0;
}

void mergesort(int *S, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergesort(S, left, mid);
    mergesort(S, mid, right);
    merge(S, left, mid, right);
  }
}

void merge(int *S, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;

  int Left[n1];
  int Right[n2];

  for (int i = 0; i < n1; i++) {
    Left[i] = S[left + i];
  }

  for (int i = 0; i < n2; i++) {
    Right[i] = S[mid + i];
  }

  int i = 0;
  int j = 0;
  int k = left;

  while (i < n2 && j < n1) {
    if (Right[i] <= Left[j]) {
      S[k++] = Right[i++];
    } else {
      S[k++] = Left[j++];
    }
  }

  while (i < n2) {
    S[k++] = Right[i++];
  }

  while (j < n1) {
    S[k++] = Left[j++];
  }
}