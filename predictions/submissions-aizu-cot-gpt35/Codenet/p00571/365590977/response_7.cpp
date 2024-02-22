#include <stdio.h>

#define N_MAX 500000

struct Data {
  long long size;
  long long value;
};

Data art[N_MAX];

bool cmp(const Data &a, const Data &b) {
  return a.size == b.size ? a.value < b.value : a.size < b.size;
}

long long Max(long long a, long long b) {
  return a > b ? a : b;
}

int main(void) {
  int N;
  scanf("%d", &N);

  for (int i = 0; i < N; ++i) {
    scanf("%lld %lld", &art[i].size, &art[i].value);
  }

  sort(art, art + N, cmp);

  long long min_size = art[0].size;
  long long sum_value = art[0].value;
  long long ans = art[0].value;

  for (int i = 1; i < N; ++i) {
    long long value = art[i].value;
    long long size = art[i].size;
    long long size_diff = size - min_size;
    long long tmp = sum_value + value - size_diff;

    if (tmp <= 0) {
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