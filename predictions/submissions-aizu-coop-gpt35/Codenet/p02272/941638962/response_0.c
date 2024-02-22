#include <stdio.h>

#define MAX 1000000001

void mergesort(int *, int, int);
void merge(int *, int, int, int);

int count = 0;

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
  printf("\n%d\n", count);
  
  return 0;
}

void mergesort(int *S, int left, int right) {
  if (left + 1 < right) {
    int mid = ((left + right) >> 1);
    mergesort(S, left, mid);
    mergesort(S, mid, right);
    merge(S, left, mid, right);
  }
}

void merge(int *S, int left, int mid, int right) {
  int temp[right - left];
  int i = left, j = mid, k = 0;
  
  while (i < mid && j < right) {
    if (S[j] < S[i]) {
      temp[k++] = S[j++];
      count += mid - i;
    } else {
      temp[k++] = S[i++];
    }
  }
  
  while (i < mid) {
    temp[k++] = S[i++];
  }
  
  while (j < right) {
    temp[k++] = S[j++];
  }
  
  for (int x = 0; x < k; x++) {
    S[left + x] = temp[x];
  }
}