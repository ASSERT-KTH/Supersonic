#include <algorithm>
#include <iostream>
using namespace std;

typedef long long llong;

struct Data {
  llong size;
  llong value;

  bool operator<(const Data &d) const {
    return size < d.size || (size == d.size && value < d.value);
  }
};

#define N_MAX 500000
Data art[N_MAX];

inline llong Max(llong a, llong b) { return a > b ? a : b; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  for (int i = 0; i < N; ++i) {
    cin >> art[i].size >> art[i].value;
  }

  sort(art, art + N);

  llong min_size = art[0].size;
  llong sum_value = art[0].value;
  llong ans = art[0].value;

  for (int i = 1; i < N; ++i) {
    llong value = art[i].value;
    llong size = art[i].size;
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

  cout << ans << endl;
  return 0;
}