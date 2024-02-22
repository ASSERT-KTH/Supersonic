#include <iostream>
using namespace std;

const int INF = 1000000001;
const int MAX = 500000;

int cnt;
int S[MAX];

void merge(int *A, int left, int mid, int right) {
  int n1, n2, i, j;
  n1 = mid - left;
  n2 = right - mid;

  int L[n1], R[n2];

  for (int i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }

  i = 0;
  j = 0;

  for (int k = left; k < right; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
    cnt++;
  }
}

void mergesort(int *A, int left, int right) {
  if (left + 1 >= right) {
    return;
  }

  int mid = (left + right) / 2;
  mergesort(A, left, mid);
  mergesort(A, mid, right);
  merge(A, left, mid, right);
}

int main() {
  int N;
  cnt = 0;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }

  mergesort(S, 0, N);

  for (int i = 0; i < N; i++) {
    if (i == N - 1) {
      cout << S[i] << endl;
    } else {
      cout << S[i] << " ";
    }
  }

  cout << cnt << endl;

  return 0;
}