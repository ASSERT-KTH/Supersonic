#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int INF = 1000000001;
const int MAX = 500000;
int cnt;
vector<int> S(MAX, 0), L(1 + MAX / 2, 0), R(1 + MAX / 2, 0);
void merge(vector<int>& A, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  for (int i = 0; i < n1; ++i) {
    L[i] = A[left + i];
  }
  for (int i = 0; i < n2; ++i) {
    R[i] = A[mid + i];
  }
  L[n1] = INF;
  R[n2] = INF;
  int i = 0, j = 0;
  int distance = right - left;
  for (int k = 0; k < distance; ++k) {
    if (L[i] <= R[j]) {
      A[left + k] = L[i];
      ++i;
    } else {
      A[left + k] = R[j];
      ++j;
    }
    ++cnt;
  }
}
void mergesort(vector<int>& A, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergesort(A, left, mid);
    mergesort(A, mid, right);
    merge(A, left, mid, right);
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cnt = 0;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> S[i];
  }
  mergesort(S, 0, N);
  for (int i = 0; i < N; ++i) {
    if (i == N - 1) {
      cout << S[i] << "\n";
    } else {
      cout << S[i] << " ";
    }
  }
  cout << cnt << "\n";
  return 0;
}