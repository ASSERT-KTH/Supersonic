#include <iostream>
using namespace std;
const int INF = 1000000001;
const int MAX = 500000;
int cnt;
int S[MAX] = {0};

void merge(int *A, int left, int mid, int right) {
  int i = left, j = mid, k = left;
  while (i < mid && j < right) {
    if (A[i] <= A[j]) {
      S[k++] = A[i++];
    } else {
      S[k++] = A[j++];
    }
    cnt++;
  }
  while (i < mid) {
    S[k++] = A[i++];
    cnt++;
  }
  while (j < right) {
    S[k++] = A[j++];
    cnt++;
  }
  for (int l = left; l < right; l++) {
    A[l] = S[l];
  }
}

void mergesort(int *A, int N) {
  for (int size = 1; size < N; size *= 2) {
    for (int left = 0; left < N - size; left += 2 * size) {
      int mid = left + size;
      int right = min(left + 2 * size, N);
      merge(A, left, mid, right);
    }
  }
}

int main() {
  int N;
  cnt = 0;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  mergesort(S, N);
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