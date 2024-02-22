#include <iostream>
#include <vector>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)

void counting_sort(vector<int>& v) {
  int n = v.size();
  int k = 0;
  for (int x : v) {
    k = max(k, x);
  }
  vector<int> cnt(k + 1), tmp(v);
  for (int x : v) {
    cnt[x]++;
  }
  for (int i = 1; i <= k; i++) {
    cnt[i] += cnt[i - 1];
  }
  for (int i = n - 1; i >= 0; i--) {
    v[cnt[tmp[i]] - 1] = tmp[i];
    cnt[tmp[i]]--;
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> A;
  A.reserve(n);
  rep(i, 0, n) {
    int x;
    cin >> x;
    A.push_back(x);
  }
  counting_sort(A);
  cout << A[0];
  rep(i, 1, A.size()) {
    cout << " " << A[i];
  }
  cout << endl;
  return 0;
}