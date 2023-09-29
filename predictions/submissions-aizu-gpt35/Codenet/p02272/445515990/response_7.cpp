#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
const int INF = 1000000001;
const int MAX = 500000;
int cnt;
int L[1 + MAX / 2], R[1 + MAX / 2];
void merge(int *A, int left, int mid, int right) {
  int n1, n2, n, i, j, k;
  n1 = mid - left;
  n2 = right - mid;
  for (i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for (i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }
  L[n1] = R[n2] = INF;
  i = j = 0;
  for (k = left; k < right; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
    cnt++;
  }
}
void mergesort(int *A, int left, int right) {
  int mid;
  if (left + 1 < right) {
    mid = (left + right) / 2;
    mergesort(A, left, mid);
    mergesort(A, mid, right);
    merge(A, left, mid, right);
  }
}
int main() {
  int N;
  cnt = 0;
  cin >> N;
  int* S = new int[N];
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
  delete[] S;
  return 0;
}
