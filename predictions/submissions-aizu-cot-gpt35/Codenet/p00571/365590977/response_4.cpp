#include <stdio.h>
#include <algorithm>

#define N_MAX 500000

struct Data {
  long long size;
  long long value;
};

bool cmp(const Data &a, const Data &b) {
  return a.size < b.size || (a.size == b.size && a.value < b.value);
}

int main(void) {
  int N;
  scanf("%d", &N);

  Data art[N_MAX];
  for (int i = 0; i < N; ++i) {
    scanf("%lld %lld", &art[i].size, &art[i].value);
  }

  std::sort(art, art + N, cmp);

  long long min_size = art[0].size;
  long long ans = art[0].value;

  for (int i = 1; i < N; ++i) {
    long long tmp = art[i].value + ans - (art[i].size - min_size);
    ans = std::max(ans, tmp);
    min_size = std::min(min_size, art[i].size);
  }

  printf("%lld\n", ans);
  return 0;
}