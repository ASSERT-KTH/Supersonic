#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(c) begin(c), end(c)

void counting_sort(vector<int> &v) {
  int n = v.size(), k = *max_element(all(v));
  vector<int> cnt(k + 1), res(n);
  for (int x : v) cnt[x]++;
  rep(i, 1, k + 1) cnt[i] += cnt[i - 1];
  for (int i = n - 1; i >= 0; i--)
    res[--cnt[v[i]]] = v[i];
  v = res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> A(n);
  rep(i, 0, n) cin >> A[i];
  counting_sort(A);
  rep(i, 0, A.size()) {
    if (i) cout << ' ';
    cout << A[i];
  }
  cout << '\n';
  return 0;
}