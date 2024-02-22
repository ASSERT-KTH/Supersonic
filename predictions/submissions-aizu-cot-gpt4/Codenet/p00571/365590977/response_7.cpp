#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;
typedef long long llong;
#define N_MAX 500000
pair<llong, llong> art[N_MAX];
inline bool cmp(const pair<llong, llong> &a, const pair<llong, llong> &b) {
  return a.first == b.first ? a.second < b.second : a.first < b.first;
}
inline llong Max(llong a, llong b) { return a > b ? a : b; }
int main(void) {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> art[i].first >> art[i].second;
  }
  if (!is_sorted(art, art + N)) {
    sort(art, art + N, cmp);
  }
  llong min_size = art[0].first;
  llong sum_value = art[0].second;
  llong ans = art[0].second;
  for (int i = 1; i < N; ++i) {
    llong value = art[i].second;
    llong size = art[i].first;
    llong tmp = sum_value + value - size + min_size;
    if (tmp < value) {
      ans = Max(ans, value);
      sum_value = value;
      min_size = size;
    } else {
      ans = Max(ans, tmp);
      sum_value += value;
    }
  }
  cout << ans << endl;
  return 0;
}