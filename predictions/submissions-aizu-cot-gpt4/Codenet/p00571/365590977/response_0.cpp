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
  for (int i = 0; i < N; ++i) {
    scanf("%lld %lld", &art[i].size, &art[i].value);
  }
  sort(art, art + N, cmp);
  llong min_size = art[0].size;
  llong sum_value = art[0].value;
  llong ans = sum_value;
  for (int i = 1; i < N; ++i) {
    Data &curr = art[i];
    llong diff = sum_value + curr.value - (curr.size - min_size);
    if (diff < curr.value) {
      ans = max(ans, curr.value);
      sum_value = curr.value;
      min_size = curr.size;
    } else {
      ans = max(ans, diff);
      sum_value += curr.value;
    }
  }
  printf("%lld\n", ans);
  return 0;
}