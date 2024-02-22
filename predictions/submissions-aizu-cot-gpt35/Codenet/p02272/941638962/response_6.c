#include <stdio.h>
#define MAX 1000000001

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
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergesort(S, left, mid);
    mergesort(S, mid, right);
    merge(S, left, mid, right);
  }
}

void merge(int *S, int left, int mid, int right) {
  int temp[right - left];
  int i = left, j = mid, k = 0;
  
  while (i < mid && j < right) {
    if (S[i] <= S[j])
      temp[k++] = S[i++];
    else
      temp[k++] = S[j++];
  }
  
  while (i < mid)
    temp[k++] = S[i++];
  
  while (j < right)
    temp[k++] = S[j++];
  
  for (int i = 0; i < k; i++)
    S[left + i] = temp[i];
}