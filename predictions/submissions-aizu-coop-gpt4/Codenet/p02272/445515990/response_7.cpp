#include <cstdio>
#define MAX 500000
#define INF 1000000001

int S[MAX] = {0}, cnt = 0;

void merge(int *A, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1 + 1], R[n2 + 1];
  
  for (int i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }
  
  L[n1] = R[n2] = INF;
  int i = 0, j = 0;
  
  for (int k = 0; k < right - left; k++) {
    if (L[i] <= R[j]) {
      A[left + k] = L[i++];
    } else {
      A[left + k] = R[j++];
    }
    cnt++;
  }
}

void mergesort(int *A, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergesort(A, left, mid);
    mergesort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  int N;
  scanf("%d", &N);
  
  for (int i = 0; i < N; i++) {
    scanf("%d", &S[i]);
  }
  
  mergesort(S, 0, N);
  
  for (int i = 0; i < N; i++) {
    printf("%d", S[i]);
    if (i == N - 1) {
      printf("\n");
    } else {
      printf(" ");
    }
  }
  
  printf("%d\n", cnt);
  return 0;
}