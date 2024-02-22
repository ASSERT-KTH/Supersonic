#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int INF = 1000000001;
const int MAX = 500000;

int cnt;
vector<int> S(MAX);
vector<int> L, R;

void merge(int *A, int left, int mid, int right) {
  int n1, n2, n, i, j;
  n1 = mid - left;
  n2 = right - mid;

  L.resize(n1 + 1);
  R.resize(n2 + 1);

  for (int i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }

  L[n1] = INF;
  R[n2] = INF;

  i = 0;
  j = 0;
  int k = left;

  while (i < n1 || j < n2) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
    cnt++;
    k++;
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

  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }

  mergesort(S.data(), 0, N);

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