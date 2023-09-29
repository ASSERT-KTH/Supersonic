#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> A(n);
  int mx = 0;
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
    mx = max(mx, A[i]);
  }

  vector<int> cnt(mx + 1);
  for (int i = 0; i < n; ++i) {
    cnt[A[i]]++;
  }

  for (int i = 1; i <= mx; ++i) {
    cnt[i] += cnt[i - 1];
  }

  vector<int> B(n);
  for (int i = n - 1; i >= 0; --i) {
    B[--cnt[A[i]]] = A[i];
  }
  A = B;

  for (int i = 0; i < n; ++i) {
    cout << A[i] << " \n"[i == n - 1];
  }

  return 0;
}