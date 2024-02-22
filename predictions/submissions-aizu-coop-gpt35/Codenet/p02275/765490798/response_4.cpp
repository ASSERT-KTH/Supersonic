#include <iostream>
#include <vector>

using namespace std;

#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define rep(i, a, b) for (size_t i = (a); i < (b); i++)
#define rrep(i, a, b) for (size_t i = (b)-1; i >= (a); i--)
#define all(c) begin(c), end(c)

const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);

template <class T>
void counting_sort(const vector<T>& v) {
  size_t n = v.size();
  T k = *max_element(all(v));
  vector<int> cnt(k + 1), tmp = v;
  cnt[0]--;
  for (auto x : v)
    cnt[x]++;
  for (size_t i = 0; i < k; i++)
    cnt[i + 1] += cnt[i];
  for (size_t i = 0; i < n; i++) {
    v[cnt[tmp[i]]] = tmp[i];
    cnt[tmp[i]]--;
  }
}

int main() {
  size_t n;
  cin >> n;
  vector<int> A(n);
  for (auto& elem : A) {
    cin >> elem;
  }
  counting_sort(A);
  cout << A[0];
  rep(i, 1, A.size()) { cout << " " << A[i]; }
  cout << endl;
  return 0;
}