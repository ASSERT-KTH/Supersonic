#include <algorithm>
#include <iostream>
using namespace std;
int tb[1112], ans[1112], N;
int nr(int a) {
  int low = 2, high = 1111, mid, ret = 1;
  while (low <= high) {
    mid = low + (high - low) / 2;
    if (tb[mid] <= a) {
      ret = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return tb[ret];
}
int calc(int z) {
  long long z3 = 1LL * z * z * z, ret = z3;
  for (int i = z; i > 0; i--) {
    long long i3 = 1LL * i * i * i, j3 = nr(z3 - i3);
    if (i3 + j3 < z3)
      ret = min(ret, z3 - i3 - j3);
    else
      break;
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 1; i < 1112; i++)
    tb[i] = i * i * i;
  for (int i = 1; i < 1112; i++)
    ans[i] = calc(i);
  while (cin >> N, N)
    cout << ans[N] << '\n';
  return 0;
}