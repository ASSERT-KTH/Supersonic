#include <algorithm>
#include <stdio.h>
using namespace std;
typedef long long llong;

#define N_MAX 500000

struct Data {
  llong combined; // Combined size and value
};

bool cmp(const Data &a, const Data &b) {
  return a.combined < b.combined;
}

inline llong Max(llong a, llong b) {
  return a > b ? a : b;
}

int main(void) {
  int N;
  scanf("%d", &N);

  Data art[N_MAX];

  // Read input values using a pointer-based approach
  llong *inputPtr = (llong *)art;
  for (int i = 0; i < N; ++i) {
    scanf("%lld %lld", inputPtr++, inputPtr++);
  }

  sort(art, art + N, cmp);

  llong min_size = art[0].combined >> 32; // Extract size from combined
  llong sum_value = art[0].combined & 0xFFFFFFFF; // Extract value from combined
  llong ans = art[0].combined & 0xFFFFFFFF; // Extract value from combined

  for (int i = 1; i < N; ++i) {
    llong combined = art[i].combined;
    llong value = combined & 0xFFFFFFFF; // Extract value from combined
    llong size = combined >> 32; // Extract size from combined

    llong tmp = sum_value + value - (size - min_size);

    if (tmp < value) {
      ans = value;
      sum_value = value;
      min_size = size;
    } else {
      ans = tmp;
      sum_value += value;
    }
  }

  printf("%lld\n", ans);
  return 0;
}