#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000001

void mergeSort(int *, int, int, int*);
void merge(int *, int, int, int, int*);

int main(void) {
  int n;
  scanf("%d", &n);
  int* S = malloc(n*sizeof(int));
  for (int i = 0; i < n; i++)
    scanf("%d", &S[i]);
  
  int count = 0;
  mergeSort(S, 0, n, &count);
  
  for (int i = 0; i < n; i++) {
    printf("%d", S[i]);
    if (i != n - 1)
      printf(" ");
  }
  printf("\n%d\n", count);
  
  free(S);
  return 0;
}

void mergeSort(int *S, int left, int right, int* count) {
  int mid;
  if (left + 1 < right) {
    mid = (left + right) / 2;
    mergeSort(S, left, mid, count);
    mergeSort(S, mid, right, count);
    merge(S, left, mid, right, count);
  }
}

void merge(int *S, int left, int mid, int right, int* count) {
  int n1 = mid - left;
  int n2 = right - mid;

  int *Left = malloc((n1+1)*sizeof(int));
  int *Right = malloc((n2+1)*sizeof(int));

  for (int i = 0; i < n1; i++)
    Left[i] = S[left + i];
  for (int i = 0; i < n2; i++)
    Right[i] = S[mid + i];
    
  Left[n1] = MAX;
  Right[n2] = MAX;
  
  int i = 0;
  int j = 0;

  for (int k = left; k < right; k++) {
    if (Left[j] > Right[i]) {
      S[k] = Right[i++];
    } else {
      S[k] = Left[j++];
    }
  }

  *count += right - left;
  
  free(Left);
  free(Right);
}