#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 500000;
int cnt;
int S[MAX] = {0};

void merge(int *A, int left, int mid, int right) {
  int i = left, j = mid, k = 0;
  int temp[right - left + 1];
  while (i < mid && j < right) {
    if (A[i] <= A[j]) {
      temp[k++] = A[i++];
    } else {
      temp[k++] = A[j++];
    }
    cnt++;
  }
  while (i < mid) {
    temp[k++] = A[i++];
    cnt++;
  }
  while (j < right) {
    temp[k++] = A[j++];
    cnt++;
  }
  for (i = left; i < right; i++) {
    A[i] = temp[i - left];
  }
}
void mergesort(int *A, int left, int right) {
  for (int m = 1; m <= right - left; m = 2*m) {
    for (int i = left; i < right; i += 2*m) {
      int mid = min(i+m, right);
      int end = min(i+2*m, right);
      merge(A, i, mid, end);
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