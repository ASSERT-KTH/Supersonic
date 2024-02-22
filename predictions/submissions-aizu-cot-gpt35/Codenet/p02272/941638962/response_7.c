#include <stdio.h>
#define MAX 1000000001

void mergesort(int *, size_t, size_t);
void merge(int *, size_t, size_t, size_t);

int main(void) {
  size_t n;
  scanf("%zu", &n);
  
  int S[n];
  for (size_t i = 0; i < n; i++)
    scanf("%d", &S[i]);

  mergesort(S, 0, n);

  for (size_t i = 0; i < n; i++) {
    printf("%d", S[i]);
    if (i != n - 1)
      printf(" ");
  }
  
  printf("\n");

  return 0;
}

void mergesort(int *S, size_t left, size_t right) {
  if (left + 1 < right) {
    size_t mid = (left + right) / 2;
    mergesort(S, left, mid);
    mergesort(S, mid, right);
    merge(S, left, mid, right);
  }
}

void merge(int *S, size_t left, size_t mid, size_t right) {
  size_t n1 = mid - left;
  size_t n2 = right - mid;
  int Left[n1 + 1];
  int Right[n2 + 1];
  
  for (size_t i = 0; i < n1; i++)
    Left[i] = S[left + i];
  
  for (size_t i = 0; i < n2; i++)
    Right[i] = S[mid + i];
  
  Left[n1] = MAX;
  Right[n2] = MAX;
  
  size_t i = 0;
  size_t j = 0;
  size_t k = left;
  
  while (k < right) {
    if (Left[j] > Right[i])
      S[k++] = Right[i++];
    else
      S[k++] = Left[j++];
  }
}