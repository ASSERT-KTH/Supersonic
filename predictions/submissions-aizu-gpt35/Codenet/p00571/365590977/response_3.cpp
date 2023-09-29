#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long llong;
struct Data {
  llong size;
  llong value;
} art[500005];
inline bool cmp(const Data &a, const Data &b) {
  return a.size < b.size || (a.size == b.size && a.value < b.value);
}
inline llong Max(llong a, llong b) { return a > b ? a : b; }
int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%lld%lld", &art[i].size, &art[i].value);
  }
  sort(art, art + N, cmp);
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
  printf("%lld\n", ans);
  return 0;
}