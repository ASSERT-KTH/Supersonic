#include <algorithm>
#include <iostream>
using namespace std;
int tb[1112], ans[1112], N;

int calc(int z) {
  int z3 = z * z * z, ret = z3;
  for (int i = 1; i < z; i++) {
    int i3 = i * i * i;
    int j3 = tb[lower_bound(tb, tb+1112, z3 - i3) - tb - 1];
    if (i3 + j3 >= z3)
      break;
    if (ret > z3 - i3 - j3)
      ret = z3 - i3 - j3;
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