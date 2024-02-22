#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
typedef long long llong;
typedef pair<llong, llong> Data;
#define N_MAX 500000

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin >> N;
  vector<Data> art(N);
  for (int i = 0; i < N; ++i) {
    cin >> art[i].first >> art[i].second;
  }
  sort(art.begin(), art.end());
  llong min_size = art[0].first;
  llong sum_value = art[0].second;
  llong ans = art[0].second;
  for (int i = 1; i < N; ++i) {
    llong tmp = sum_value + art[i].second - (art[i].first - min_size);
    if (tmp < art[i].second) {
      ans = max(ans, art[i].second);
      sum_value = art[i].second;
      min_size = art[i].first;
    } else {
      ans = max(ans, tmp);
      sum_value += art[i].second;
    }
  }
  cout << ans << "\n";
  return 0;
}