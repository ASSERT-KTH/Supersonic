#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
const int INF = 1000000001;
const int MAX = 500000;
int cnt;
int S[MAX] = {0};
void merge(int *A, int left, int mid, int right) {
  int i = left, j = mid;
  int k = 0;
  while (i < mid && j < right) {
    if (A[i] <= A[j]) {
      S[k] = A[i];
      i++;
    } else {
      S[k] = A[j];
      j++;
    }
    k++;
  }
  while (i < mid) {
    S[k] = A[i];
    i++;
    k++;
  }
  while (j < right) {
    S[k] = A[j];
    j++;
    k++;
  }
  for (i = left; i < right; i++) {
    A[i] = S[i - left];
  }
}
void mergesort(int *A, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergesort(A, left, mid);
    mergesort(A, mid, right);
    merge(A, left, mid, right);
    cnt += right - left - 1;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int N;
  cnt = 0;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  mergesort(S, 0, N);
  for (int i = 0; i < N; i++) {
    if (i == N - 1) {
      cout << S[i] << '\n';
    } else {
      cout << S[i] << " ";
    }
  }
  cout << cnt << '\n';
  return 0;
}