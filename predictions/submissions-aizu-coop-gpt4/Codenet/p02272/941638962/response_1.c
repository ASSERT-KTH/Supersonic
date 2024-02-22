#include <stdio.h>

#define MAX 1000000001

void mergesort(int *, int, int, int *, int *);
void merge(int *, int, int, int, int *, int *);

int main(void) {
  int S[500000];
  int n;
  scanf("%d", &n);
  
  int Left[n], Right[n]; // Declare auxiliary arrays here
  
  for (int i = 0; i < n; i++)
    scanf("%d", &S[i]);
    
  mergesort(S, 0, n, Left, Right);
  
  for (int i = 0; i < n; i++) {
    printf("%d", S[i]);
    if (i != n - 1)
      printf(" ");
  }
  printf("\n");
  return 0;
}

void mergesort(int *S, int left, int right, int *Left, int *Right) {
  int mid;
  if (left + 1 < right) {
    mid = (left + right) / 2;
    mergesort(S, left, mid, Left, Right);
    mergesort(S, mid, right, Left, Right);
    merge(S, left, mid, right, Left, Right);
  }
}

void merge(int *S, int left, int mid, int right, int *Left, int *Right) {
  int n1 = mid - left;
  int n2 = right - mid;
  for (int i = 0; i < n1; i++)
    Left[i] = S[left + i];
  for (int i = 0; i < n2; i++)
    Right[i] = S[mid + i];
  Left[n1] = MAX;
  Right[n2] = MAX;
  int i = 0;
  int j = 0;
  for (int k = left; k < right; k++) {
    if (Left[j] > Right[i])
      S[k] = Right[i++];
    else
      S[k] = Left[j++];
  }
}