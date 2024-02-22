#include <algorithm>
#include <iostream>
using namespace std;
typedef long long llong;
struct Data {
  llong size;
  llong value;
};
#define N_MAX 500000
Data art[N_MAX];
inline bool cmp(const Data &a, const Data &b) {
  return a.size == b.size ? a.value < b.value : a.size < b.size;
}
int main(void) {
  std::ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  int i;
  for (i = 0; i < N; ++i) {
    cin >> art[i].size >> art[i].value;
  }
  sort(art, art + N, cmp);
  llong min_size = art[0].size;
  llong sum_value = art[0].value;
  llong ans = art[0].value;
  for (i = 1; i < N; ++i) {
    llong value = art[i].value;
    llong size = art[i].size;
    llong tmp = sum_value + value - (size - min_size);
    if (tmp < value) {
      ans = std::max(ans, value);
      sum_value = value;
      min_size = size;
    } else {
      ans = std::max(ans, tmp);
      sum_value += value;
    }
  }
  cout << ans << "\n";
  return 0;
}