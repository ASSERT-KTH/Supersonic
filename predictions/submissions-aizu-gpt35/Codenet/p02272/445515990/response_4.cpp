#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
const int INF = 1000000001;
const int MAX = 500000;
int cnt;
int S[MAX] = {0}, L[1 + MAX / 2] = {0}, R[1 + MAX / 2] = {0};
void merge(int *A, int left, int mid, int right) {
  int n1, n2, n, i, j, k;
  n1 = mid - left;
  n2 = right - mid;
  int *L = new int[n1 + 1];
  int *R = new int[n2 + 1];
  for (i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for (i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }
  L[n1] = INF;
  R[n2] = INF;
  i = 0;
  j = 0;
  for (k = left; k < right; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
    cnt++;
  }
  delete[] L;
  delete[] R;
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