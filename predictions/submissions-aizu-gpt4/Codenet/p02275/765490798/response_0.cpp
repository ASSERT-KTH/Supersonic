#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void counting_sort(vector<int> &v) {
  int mx = *max_element(v.begin(), v.end());
  vector<int> cnt(mx + 1, 0);
  for (int x : v) ++cnt[x];
  int idx = 0;
  for (int i = 0; i <= mx; ++i)
    for (int j = 0; j < cnt[i]; ++j)
      v[idx++] = i;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> A(n);
  for (auto &a : A) cin >> a;
  counting_sort(A);
  for (const auto &a : A) cout << a << " ";
  cout << "\n";
  return 0;
}