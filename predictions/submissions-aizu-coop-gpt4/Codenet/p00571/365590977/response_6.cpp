#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long llong;
struct Data {
  llong size;
  llong value;
};

inline bool cmp(const Data &a, const Data &b) {
  return a.size == b.size ? a.value < b.value : a.size < b.size;
}

inline llong Max(llong a, llong b) { return a > b ? a : b; }

int main(void) {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);

  int N;
  cin >> N;
  vector<Data> art(N);
  for (int i = 0; i < N; ++i) {
    cin >> art[i].size >> art[i].value;
  }
  sort(art.begin(), art.end(), cmp);
  llong min_size = art[0].size;
  llong sum_value = art[0].value;
  llong ans = art[0].value;
  for (int i = 1; i < N; ++i) {
    llong value = art[i].value;
    llong size = art[i].size;
    llong tmp = sum_value + value - (size - min_size);
    if (tmp < value) {
      ans = Max(ans, value);
      sum_value = value;
      min_size = size;
    } else {
      ans = Max(ans, tmp);
      sum_value += value;
    }
  }
  cout << ans << "\n";
  return 0;
}