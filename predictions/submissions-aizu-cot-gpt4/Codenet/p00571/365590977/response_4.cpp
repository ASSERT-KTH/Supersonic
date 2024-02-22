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

int main(void) {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%lld %lld", &art[i].size, &art[i].value);
  }
  sort(art, art + N, [](const Data &a, const Data &b) {
    return a.size == b.size ? a.value < b.value : a.size < b.size;
  });
  llong min_size = art[0].size;
  llong sum_value = art[0].value;
  llong ans = art[0].value;
  for (int i = 1; i < N; ++i) {
    llong tmp = sum_value + art[i].value - (art[i].size - min_size);
    if (tmp < art[i].value) {
      ans = std::max(ans, art[i].value);
      sum_value = art[i].value;
      min_size = art[i].size;
    } else {
      ans = std::max(ans, tmp);
      sum_value += art[i].value;
    }
  }
  printf("%lld\n", ans);
  return 0;
}