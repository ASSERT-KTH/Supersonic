#include <bits/stdc++.h>
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(c) begin(c), end(c)
const int INF =
    sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);

template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T> bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
void counting_sort(std::vector<int> &v) {
  int n = v.size(), k = *max_element(v.begin(), v.end());
  std::vector<int> cnt(k + 1);
  cnt[0]--;
  for (int x : v)
    cnt[x]++;
  for (int i = 0; i < k; i++)
    cnt[i + 1] += cnt[i];
  for (int i = n - 1; i >= 0; i--) {
    v[cnt[v[i]]] = v[i];
    cnt[v[i]]--;
  }
}
signed main() {
  int n;
  std::cin >> n;
  std::vector<int> A(n);
  rep(i, 0, n) { std::cin >> A[i]; }
  counting_sort(A);
  std::cout << A[0];
  rep(i, 1, A.size()) { std::cout << " " << A[i]; }
  std::cout << std::endl;
  return 0;
}