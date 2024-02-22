#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define all(c) begin(c), end(c)

const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);

inline bool chmax(int &a, const int &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

inline bool chmin(int &a, const int &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

void counting_sort(vector<int> &v) {
  int n = v.size();
  map<int, int> cnt;
  vector<int> tmp(v);
  for (int x : v)
    cnt[x]++;
  int i = 0;
  for (auto &p : cnt) {
    p.second += i;
    i = p.second;
  }
  for (int i = n - 1; i >= 0; i--) {
    v[--cnt[tmp[i]]] = tmp[i];
  }
}

signed main() {
  int n;
  cin >> n;
  vector<int> A(n);
  rep(i, 0, n) { cin >> A[i]; }
  counting_sort(A);
  cout << A[0];
  rep(i, 1, A.size()) { cout << " " << A[i]; }
  cout << endl;
  return 0;
}