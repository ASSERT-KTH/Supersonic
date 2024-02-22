#include <algorithm>
#include <iostream>
using namespace std;
int tb[1112], ans[1112], N;
int nr(int a) {
  int low = 1, high = 1111, ret = 1;
  while (low <= high) {
    int mid = (low + high) / 2;
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
  int z3 = z * z * z;
  int ret = z3 - nr(z3 - 1) - 1;
  for (int i = 1; i < z; i++) {
    int i3 = i * i * i, j3 = nr(z3 - i3);
    if (i3 + j3 >= z3)
      break;
    ret = min(ret, z3 - i3 - j3);
  }
  return ret;
}
int main() {
  for (int i = 1; i < 1112; i++)
    tb[i] = i * i * i;
  for (int i = 1; i < 1112; i++)
    ans[i] = calc(i);
  while (cin >> N, N)
    cout << ans[N] << endl;
}