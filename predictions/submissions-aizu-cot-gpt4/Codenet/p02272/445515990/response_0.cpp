#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& A, int left, int mid, int right, int& cnt) {
  int n1 = mid - left;
  int n2 = right - mid;
  vector<int> L(A.begin() + left, A.begin() + mid);
  vector<int> R(A.begin() + mid, A.begin() + right);
  int i = 0, j = 0;
  for (int k = left; k < right; k++) {
    if (j >= n2 || (i < n1 && L[i] <= R[j])) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
    cnt++;
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
  int N;
  cin >> N;
  vector<int> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  int cnt = 0;
  mergesort(S, 0, N, cnt);
  for (int i = 0; i < N; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << S[i];
  }
  cout << "\n" << cnt << "\n";
  return 0;
}