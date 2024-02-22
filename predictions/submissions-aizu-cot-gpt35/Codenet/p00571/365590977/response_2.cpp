#include <algorithm>
#include <cstdio>
#include <tuple>

#define N_MAX 500000

struct Data {
  int size;
  int value;
};

bool cmp(const Data& a, const Data& b) {
  return std::tie(a.size, a.value) < std::tie(b.size, b.value);
}

int main(void) {
  int N;
  std::scanf("%d", &N);

  Data art[N_MAX];
  for (int i = 0; i < N; ++i) {
    std::scanf("%d %d", &art[i].size, &art[i].value);
  }

  std::sort(art, art + N, cmp);

  int min_size = art[0].size;
  int sum_value = art[0].value;
  int ans = art[0].value;

  for (int i = 1; i < N; ++i) {
    int value = art[i].value;
    int size = art[i].size;

    if (sum_value + value - (size - min_size) < value) {
      ans = std::max(ans, value);
      sum_value = value;
      min_size = size;
    } else {
      ans = std::max(ans, sum_value + value);
      sum_value += value;
    }
  }

  std::printf("%lld\n", static_cast<long long>(ans));
  return 0;
}