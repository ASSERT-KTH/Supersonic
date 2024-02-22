#include <stdio.h>
typedef long long llong;
struct Data {
  llong size;
  llong value;
};
#define N_MAX 500000
Data art[N_MAX];
bool cmp(const Data &a, const Data &b) {
  return a.size < b.size || (a.size == b.size && a.value < b.value);
}
llong Max(llong a, llong b) { return std::max(a, b); }
int main(void) {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%lld %lld", &art[i].size, &art[i].value);
  }
  std::sort(art, art + N, cmp);
  llong sum_value = 0;
  llong ans = 0;
  for (int i = 0; i < N; ++i) {
    llong value = art[i].value;
    llong size = art[i].size;
    llong tmp = sum_value + value - size;
    if (tmp < value) {
      ans = Max(ans, value);
      sum_value = value;
    } else {
      ans = Max(ans, tmp);
      sum_value += value;
    }
  }
  printf("%lld\n", ans);
  return 0;
}