#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000000001

void mergesort(int *, int, int);
void merge(int *, int, int, int);

int n;

int main(void) {
  int S[500000];
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &S[i]);
  mergesort(S, 0, n);
  for (int i = 0; i < n; i++) {
    printf("%d", S[i]);
    if (i != n - 1)
      printf(" ");
  }
  printf("\n%d\n", n - 1);  // Print number of merge operations directly
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
  
  int *Left = (int*) malloc((n1 + 1) * sizeof(int));
  int *Right = (int*) malloc((n2 + 1) * sizeof(int));
  
  memcpy(Left, &S[left], n1 * sizeof(int));
  memcpy(Right, &S[mid], n2 * sizeof(int));
  
  Left[n1] = MAX;
  Right[n2] = MAX;
  int i = 0, j = 0;
  for (int k = left; k < right; k++) {
    if (Left[j] > Right[i])
      S[k] = Right[i++];
    else
      S[k] = Left[j++];
  }
  free(Left);
  free(Right);
}