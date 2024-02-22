#include <algorithm>
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

struct Data {
  int64_t size;
  int64_t value;
};

const int N_MAX = 500000;
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
  
  std::sort(art, art + N, cmp);
  
  int64_t min_size = art[0].size;
  int64_t sum_value = art[0].value;
  int64_t ans = art[0].value;
  
  for (int i = 1; i < N; ++i) {
    int64_t value = art[i].value;
    int64_t size = art[i].size;
    int64_t tmp = sum_value + value - (size - min_size);
    
    if (tmp < value) {
      ans = std::max(ans, value);
      sum_value = value;
      min_size = size;
    } else {
      ans = std::max(ans, tmp);
      sum_value += value;
    }
  }
  
  printf("%lld\n", ans);
  return 0;
}