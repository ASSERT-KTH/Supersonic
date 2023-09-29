#include <vector>
#include <iostream>
using namespace std;

constexpr int MAX = 500000;
constexpr int INF = 1000000001;
int cnt;
vector<int> S(MAX), L(MAX / 2 + 1), R(MAX / 2 + 1);

void merge(int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  copy(S.begin() + left, S.begin() + mid, L.begin());
  copy(S.begin() + mid, S.begin() + right, R.begin());
  L[n1] = R[n2] = INF;
  int i = 0, j = 0;
  for (int k = left; k < right; ++k) {
    cnt++;
    S[k] = (L[i] <= R[j]) ? L[i++] : R[j++];
  }
}

void mergesort(int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergesort(left, mid);
    mergesort(mid, right);
    merge(left, mid, right);
  }
}

int main() {
  int N;
  cnt = 0;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  mergesort(0, N);
  for (int i = 0; i < N; i++) {
    cout << S[i];
    if(i != N - 1) cout << " ";
  }
  cout << "\n" << cnt << "\n";
  return 0;
}