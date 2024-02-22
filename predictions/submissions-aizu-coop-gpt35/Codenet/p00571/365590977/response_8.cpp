#include <algorithm>
#include <stdio.h>
using namespace std;
typedef long long llong;
struct Data {
  llong size;
  llong value;
};
inline llong Max(llong a, llong b) { return a > b ? a : b; }
int main(void) {
  int N;
  scanf("%d", &N);
  Data* art = new Data[N];
  int i;
  for (i = 0; i < N; ++i) {
    scanf("%lld %lld", &art[i].size, &art[i].value);
  }
  
  // Counting sort
  const int size_max = 1000000; // maximum size of art pieces
  int* frequency = new int[size_max + 1]{0};
  for (i = 0; i < N; ++i) {
    frequency[art[i].size]++;
  }
  int* prefix_sum = new int[size_max + 1]{0};
  for (i = 1; i <= size_max; ++i) {
    prefix_sum[i] = prefix_sum[i - 1] + frequency[i - 1];
  }
  Data* sorted_art = new Data[N];
  for (i = 0; i < N; ++i) {
    int pos = prefix_sum[art[i].size]++;
    sorted_art[pos] = art[i];
  }
  delete[] frequency;
  delete[] prefix_sum;
  delete[] art;
  
  llong min_size = sorted_art[0].size;
  llong sum_value = sorted_art[0].value;
  llong ans = sorted_art[0].value;
  for (i = 1; i < N; ++i) {
    llong value = sorted_art[i].value;
    llong size = sorted_art[i].size;
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
  
  delete[] sorted_art;
  
  return 0;
}