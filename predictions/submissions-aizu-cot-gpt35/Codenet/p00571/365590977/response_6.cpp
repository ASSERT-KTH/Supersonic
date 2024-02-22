#include <algorithm>
#include <stdio.h>

using llong = long long;

struct Data {
  llong size;
  llong value;
};

#define N_MAX 500000

Data art[N_MAX];

bool cmp(const Data &a, const Data &b) {
  return a.size == b.size ? a.value < b.value : a.size < b.size;
}

llong Max(llong a, llong b) {
  return std::max(a, b);
}

int main(void) {
  int N;
  scanf("%d", &N);

  for (int i = 0; i < N; ++i) {
    scanf("%lld %lld", &art[i].size, &art[i].value);
  }

  std::sort(art, art + N, cmp);

  llong ans = art[0].value;
  llong sum_value = art[0].value;
  llong min_size = art[0].size;

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