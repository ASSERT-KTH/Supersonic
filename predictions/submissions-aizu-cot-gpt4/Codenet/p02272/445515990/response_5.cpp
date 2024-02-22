#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1000000001;
const int MAX = 500000;
int cnt;
int S[MAX] = {0};
void merge(int *A, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  int i = 0, j = 0;
  for (int k = left; k < right; k++) {
    if ((i < n1 && A[left + i] <= A[mid + j]) || j >= n2) {
      A[k] = A[left + i++];
    } else {
      A[k] = A[mid + j++];
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
  cnt = 0;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &S[i]);
  }
  mergesort(S, 0, N);
  for (int i = 0; i < N; i++) {
    printf("%d ", S[i]);
  }
  printf("\n%d\n", cnt);
  return 0;
}