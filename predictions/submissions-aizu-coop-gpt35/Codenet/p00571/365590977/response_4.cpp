#include <stdio.h>

typedef long long llong;
struct Data {
  llong size;
  llong value;
};
#define N_MAX 500000
Data art[N_MAX];

inline bool cmp(const Data &a, const Data &b) {
  return a.value < b.value;
}

int main(void) {
  int N;
  scanf("%d", &N);

  for (int i = 0; i < N; ++i) {
    scanf("%lld %lld", &art[i].size, &art[i].value);
  }

  llong ans = art[0].value;
  llong min_size = art[0].size;
  llong sum_value = art[0].value;

  for (int i = 1; i < N; ++i) {
    llong value = art[i].value;
    llong size = art[i].size;
    llong tmp = sum_value + value - (size - min_size);
    if (tmp < value) {
      ans = value;
      sum_value = value;
      min_size = size;
    } else {
      ans = tmp;
      sum_value += value;
    }
  }

  printf("%lld\n", ans);
  return 0;
}