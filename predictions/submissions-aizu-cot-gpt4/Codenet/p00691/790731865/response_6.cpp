#include <algorithm>
#include <iostream>
using namespace std;
int tb[1112], ans[1112], N;

int nr(int a) {
  int start = 2, end = 1111, mid, ret = 1;
  while (start <= end) {
    mid = (start + end) / 2;
    if (tb[mid] > a)
      end = mid - 1;
    else {
      ret = mid;
      start = mid + 1;
    }
  }
  return tb[ret];
}

int calc(int z) {
  int z3 = z * z * z;
  int ret = z3;
  for (int i = 2; i < z; i++) {
    int i3 = i * i * i;
    int j3 = nr(z3 - i3);
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