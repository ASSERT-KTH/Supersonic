#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long llong;
struct Data {
  llong size;
  llong value;
};

inline bool cmp(const Data &a, const Data &b) {
  return a.size == b.size ? a.value < b.value : a.size < b.size;
}

inline llong Max(llong a, llong b) { return a > b ? a : b; }

int main(void) {
  int N;
  scanf("%d", &N);
  
  vector<Data> artVect(N);
  
  for (int i = 0; i < N; ++i) {
    scanf("%lld %lld", &artVect[i].size, &artVect[i].value);
  }
  
  sort(artVect.begin(), artVect.end(), cmp);
  
  llong min_size = artVect[0].size;
  llong sum_value = artVect[0].value;
  llong ans = artVect[0].value;
  llong value, size, tmp;
  
  for (const auto &item : artVect) {
    value = item.value;
    size = item.size;
    tmp = sum_value + value - (size - min_size);
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