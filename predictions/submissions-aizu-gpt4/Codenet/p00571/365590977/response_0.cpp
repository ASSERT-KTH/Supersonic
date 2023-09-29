#include <algorithm>
#include <stdio.h>
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
  int N;
  scanf("%d", &N);
  llong min_size = 0, sum_value = 0, ans = 0, size, value;
  for (int i = 0; i < N; ++i) {
    scanf("%lld %lld", &size, &value);
    art[i] = Data{size, value};
  }
  sort(art, art + N, cmp);
  for (int i = 0; i < N; ++i) {
    llong tmp = sum_value + art[i].value - (art[i].size - min_size);
    if (tmp < art[i].value) {
      ans = max(ans, art[i].value);
      sum_value = art[i].value;
      min_size = art[i].size;
    } else {
      ans = max(ans, tmp);
      sum_value += art[i].value;
    }
  }
  printf("%lld\n", ans);
  return 0;
}