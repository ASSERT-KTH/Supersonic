#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 500000;
int L[MAX / 2], R[MAX / 2];

void merge(int *A, int left, int mid, int right, int& cnt) {
  int n1 = mid - left;
  int n2 = right - mid;
  copy(A + left, A + mid, L);
  copy(A + mid, A + right, R);
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

void mergesort(int *A, int left, int right, int& cnt) {
  if (left+1 < right) {
    int mid = (left + right)/2;
    mergesort(A, left, mid, cnt);
    mergesort(A, mid, right, cnt);
    merge(A, left, mid, right, cnt);
  }
}

int main() {
  int N, S[MAX], cnt = 0;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &S[i]);
  }
  mergesort(S, 0, N, cnt);
  for (int i = 0; i < N; i++) {
    printf("%d%c", S[i], i==N-1 ? '\n' : ' ');
  }
  printf("%d\n", cnt);
  return 0;
}