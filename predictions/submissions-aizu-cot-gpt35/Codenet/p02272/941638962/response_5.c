#include <stdio.h>
#define MAX 1000000001

void mergesort(int *, int);
void merge(int *, int, int, int, int);
int main(void) {
  int S[500000];
  int n, i;
  
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &S[i]);
    
  mergesort(S, n);
  
  for (i = 0; i < n; i++) {
    printf("%d", S[i]);
    if (i != n - 1)
      printf(" ");
  }
  printf("\n");
  
  return 0;
}

void mergesort(int *S, int n) {
  int curr_size;
  int left_start;
  
  for (curr_size = 1; curr_size < n; curr_size = 2 * curr_size) {
    for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
      int mid = left_start + curr_size - 1;
      int right_end = left_start + 2 * curr_size - 1;
      
      if (right_end >= n) {
        right_end = n - 1;
      }
      
      merge(S, left_start, mid, right_end, n);
    }
  }
}

void merge(int *S, int left, int mid, int right, int n) {
  int i, j, k;
  int n1 = mid - left + 1;
  int n2 = right - mid;
  
  int Left[n1], Right[n2];
  
  for (i = 0; i < n1; i++) {
    Left[i] = S[left + i];
  }
  
  for (j = 0; j < n2; j++) {
    Right[j] = S[mid + 1 + j];
  }
  
  i = 0;
  j = 0;
  k = left;
  
  while (i < n1 && j < n2) {
    if (Left[i] <= Right[j]) {
      S[k] = Left[i];
      i++;
    } else {
      S[k] = Right[j];
      j++;
    }
    k++;
  }
  
  while (i < n1) {
    S[k] = Left[i];
    i++;
    k++;
  }
  
  while (j < n2) {
    S[k] = Right[j];
    j++;
    k++;
  }
}