#include <stdio.h>

typedef long long llong;

struct Data {
  llong size;
  llong value;
};

#define N_MAX 500000
Data art[N_MAX];

inline int cmp(const void *a, const void *b) {
  Data *da = (Data *)a;
  Data *db = (Data *)b;
  return da->size == db->size ? da->value - db->value : da->size - db->size;
}

inline llong Max(llong a, llong b) { return a - ((a - b) & ((a - b) >> (sizeof(llong) * 8 - 1))); }

inline llong readll() {
  llong ret = 0;
  char c = getchar_unlocked();
  while (c < '0' || c > '9') c = getchar_unlocked();
  while (c >= '0' && c <= '9') {
    ret = (ret << 3) + (ret << 1) + c - '0';
    c = getchar_unlocked();
  }
  return ret;
}

int main(void) {
  int N = readll();
  register int i;
  for (i = 0; i < N; ++i) {
    art[i].size = readll();
    art[i].value = readll();
  }
  qsort(art, N, sizeof(Data), cmp);
  llong min_size = art[0].size;
  llong sum_value = art[0].value;
  llong ans = art[0].value;
  for (i = 1; i < N; ++i) {
    llong tmp = sum_value + art[i].value - (art[i].size - min_size);
    if (tmp < art[i].value) {
      ans = Max(ans, art[i].value);
      sum_value = art[i].value;
      min_size = art[i].size;
    } else {
      ans = Max(ans, tmp);
      sum_value += art[i].value;
    }
  }
  printf("%lld\n", ans);
  return 0;
}