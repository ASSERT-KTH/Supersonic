#include <stdio.h>

struct Data {
  long long size;
  long long value;
};

const int N_MAX = 500000;

bool cmp(const Data &a, const Data &b) {
  return a.size == b.size ? a.value < b.value : a.size < b.size;
}

long long Max(long long a, long long b) {
  return a > b ? a : b;
}

int main(void) {
  int N;
  scanf("%d", &N);

  Data art[N_MAX];

  for (auto &a : art) {
    scanf("%lld %lld", &a.size, &a.value);
  }

  std::sort(art, art + N, cmp);

  long long min_size = art[0].size;
  long long sum_value = art[0].value;
  long long ans = art[0].value;

  for (int i = 1; i < N; ++i) {
    long long value = art[i].value;
    long long size = art[i].size;
    long long tmp = sum_value + value - (size - min_size);

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