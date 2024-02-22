#include <algorithm>
#include <stdio.h>
using namespace std;

struct Data {
  long long size;
  long long value;
};

#define N_MAX 500000
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

  // Sort the art array using quicksort
  sort(art, art + N, cmp);

  long long min_size = art[0].size;
  long long sum_value = art[0].value;
  long long ans = art[0].value;

  for (int i = 1; i < N; ++i) {
    long long value = art[i].value;
    long long size = art[i].size;

    // Simplify the calculation of tmp
    long long tmp = max(sum_value + value, value - (size - min_size));
  
    if (tmp < value) {
      ans = max(ans, value);
      sum_value = value;
      min_size = size;
    } else {
      ans = max(ans, tmp);
      sum_value += value;
    }
  }

  printf("%lld\n", ans);
  return 0;
}