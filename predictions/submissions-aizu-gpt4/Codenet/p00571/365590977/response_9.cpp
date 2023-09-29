#include <algorithm>
#include <stdio.h>

struct Data {
  long long size;
  long long value;
};

inline bool cmp(const Data &a, const Data &b) {
  return a.size == b.size ? a.value < b.value : a.size < b.size;
}

int main(void) {
  static Data art[500000];
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%lld %lld", &art[i].size, &art[i].value);
  }
  std::sort(art, art + N, cmp);
  long long min_size = art[0].size;
  long long sum_value = art[0].value;
  long long ans = sum_value;
  for (int i = 1; i < N; ++i) {
    sum_value += art[i].value;
    if (sum_value - (art[i].size - min_size) < art[i].value) {
      sum_value = art[i].value;
      min_size = art[i].size;
    }
    ans = std::max(ans, sum_value - (art[i].size - min_size));
  }
  printf("%lld\n", ans);
  return 0;
}