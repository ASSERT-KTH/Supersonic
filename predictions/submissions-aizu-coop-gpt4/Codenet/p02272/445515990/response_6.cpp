#include <cstdio>
#define MAX 500000
#define INF 2000000000

int N;
int cnt;
int S[MAX] = {0}, L[MAX / 2 + 2], R[MAX / 2 + 2];

void merge(int *A, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  for (int i = 0; i < n1; i++) L[i] = A[left + i];
  for (int i = 0; i < n2; i++) R[i] = A[mid + i];
  int i = 0, j = 0;
  for (int k = left; k < right; k++) {
    if (j >= n2 || (i < n1 && L[i] <= R[j])) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
    cnt++;
  }
}

void mergesort(int *A, int left, int right) {
  if (left+1 < right) {
    int mid = (left + right)>>1;
    mergesort(A, left, mid);
    mergesort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  cnt = 0;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &S[i]);
  mergesort(S, 0, N);
  for (int i = 0; i < N; i++) {
    if (i) printf(" ");
    printf("%d", S[i]);
  }
  printf("\n%d\n", cnt);
  return 0;
}