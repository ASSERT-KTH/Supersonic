#include <algorithm>
#include <iostream>
using namespace std;

int nr(int a) {
  int ret = 1;
  for (int i = 2; i < 1112; i++) {
    int tb = i * i * i;
    if (tb > a)
      break;
    ret = i;
  }
  return ret * ret * ret;
}

int calc(int z) {
  int z3 = z * z * z, ret = z3;
  for (int i = 1; i < z; i++) {
    int i3 = i * i * i;
    if (z3 - i3 <= i3)
      break;
    int j3 = nr(z3 - i3);
    ret = min(ret, z3 - i3 - j3);
  }
  return ret;
}

int main() {
  int ans[1112];
  for (int i = 1; i < 1112; i++)
    ans[i] = calc(i);
  int N;
  while (cin >> N, N)
    cout << ans[N] << endl;
}