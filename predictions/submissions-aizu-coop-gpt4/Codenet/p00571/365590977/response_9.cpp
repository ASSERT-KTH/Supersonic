#include <algorithm>
#include <stdio.h>
using namespace std;
typedef long long llong;
#define N_MAX 500000
pair<llong, llong> art[N_MAX];

bool cmp(const pair<llong, llong> &a, const pair<llong, llong> &b) {
  return a.first == b.first ? a.second < b.second : a.first < b.first;
}
int main(void) {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%lld %lld", &art[i].first, &art[i].second);
  }
  sort(art, art + N, cmp);
  llong min_size = art[0].first;
  llong sum_value = art[0].second;
  llong ans = art[0].second;
  for (int i = 1; i < N; ++i) {
    llong value = art[i].second;
    llong size = art[i].first;
    llong tmp = sum_value + value - (size - min_size);
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