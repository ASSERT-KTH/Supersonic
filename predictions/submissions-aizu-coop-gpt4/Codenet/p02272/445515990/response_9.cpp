#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& A, int left, int mid, int right, int& cnt) {
  int n = right - left;
  vector<int> tmp(n);
  int i = left, j = mid, k = 0;
  while (i < mid && j < right) {
    if (A[i] <= A[j]) {
      tmp[k++] = A[i++];
    } else {
      tmp[k++] = A[j++];
      cnt += mid - i; // count inversions
    }
  }
  while (i < mid) {
    tmp[k++] = A[i++];
  }
  while (j < right) {
    tmp[k++] = A[j++];
  }
  for (i = 0; i < n; ++i) {
    A[left + i] = tmp[i];
  }
}

void mergesort(vector<int>& A, int left, int right, int& cnt) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergesort(A, left, mid, cnt);
    mergesort(A, mid, right, cnt);
    merge(A, left, mid, right, cnt);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  int cnt = 0;
  mergesort(S, 0, N, cnt);
  for (int i = 0; i < N; i++) {
    if (i > 0) cout << " ";
    cout << S[i];
  }
  cout << "\n" << cnt << "\n";
  return 0;
}