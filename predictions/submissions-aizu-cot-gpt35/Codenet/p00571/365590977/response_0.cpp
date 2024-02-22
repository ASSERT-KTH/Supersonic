#include <stdio.h>
#include <algorithm>

struct Data {
  long long size;
  long long value;
};

#define N_MAX 500000
Data art[N_MAX];

bool cmp(const Data &a, const Data &b) {
  return a.size == b.size ? a.value < b.value : a.size < b.size;
}

int main(void) {
  int N;
  scanf("%d", &N);
  
  for (int i = 0; i < N; i++) {
    scanf("%lld %lld", &art[i].size, &art[i].value);
  }
  
  std::sort(art, art + N, cmp);
  
  long long min_size = art[0].size;
  long long sum_value = art[0].value;
  long long ans = art[0].value;
  
  for (int i = 1; i < N; i++) {
    long long tmp = sum_value + art[i].value - (art[i].size - min_size);
    
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