#include <iostream>
#include <vector>
using namespace std;

const int INF = 1000000001;

void merge(vector<int>& A, int left, int mid, int right) {
  vector<int> L(A.begin() + left, A.begin() + mid);
  vector<int> R(A.begin() + mid, A.begin() + right);

  L.push_back(INF);
  R.push_back(INF);

  int i = 0;
  int j = 0;

  for (int k = left; k < right; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
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
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;

  vector<int> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }

  int cnt = 0;
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