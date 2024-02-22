#include <stdio.h>
using namespace std;

typedef long long llong;

struct Data {
  llong size;
  llong value;
};

#define N_MAX 500000

void sort(Data* first, Data* last, bool (*comp)(const Data&, const Data&));

inline bool cmp(const Data& a, const Data& b) {
  return (a.size + a.value) < (b.size + b.value);
}

int main(void) {
  int N;
  scanf("%d", &N);

  Data* art = new Data[N];

  for (int i = 0; i < N; ++i) {
    scanf("%lld %lld", &art[i].size, &art[i].value);
  }

  sort(art, art + N, cmp);

  llong sum_value = art[0].value;
  llong ans = art[0].value;

  for (int i = 1; i < N; ++i) {
    llong value = art[i].value;
    llong size = art[i].size;
    llong tmp = sum_value + value - (size - art[0].size);

    if (tmp < value) {
      ans = max(ans, value);
      sum_value = value;
    } else {
      ans = max(ans, tmp);
      sum_value += value;
    }
  }

  printf("%lld\n", ans);

  delete[] art;

  return 0;
}