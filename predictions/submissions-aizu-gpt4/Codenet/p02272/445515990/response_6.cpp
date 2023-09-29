#include <iostream>
#include <vector>
using namespace std;
const int INF = 1000000001;

void merge(vector<int>& A, int left, int mid, int right, int& cnt) {
  int n1 = mid - left;
  int n2 = right - mid;
  vector<int> L(A.begin() + left, A.begin() + mid);
  vector<int> R(A.begin() + mid, A.begin() + right);
  L.push_back(INF);
  R.push_back(INF);
  int i = 0, j = 0;
  for (int k = left; k < right; k++) {
    if (L[i] <= R[j]) {
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
  int N, cnt = 0;
  cin >> N;
  vector<int> S(N);
  for (int& s : S) cin >> s;
  mergesort(S, 0, N, cnt);
  for (int i = 0; i < N; i++) {
    if (i) cout << " ";
    cout << S[i];
  }
  cout << "\n" << cnt << "\n";
  return 0;
}