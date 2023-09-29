#include <algorithm>
#include <iostream>
using namespace std;
int tb[1120], ans[1120], N;
int nr(int a) {
  int ret = 1;
  for (int i = 2; i < 1120; i++) {
    if (tb[i] > a)
      break;
    ret = i;
  }
  return tb[ret];
}
int calc(int z) {
  int z3 = z * z * z, ret = z3;
  for (int i = 1; i < z; i++) {
    int i3 = i * i * i, j3 = nr(z3 - i3);
    if (i3 + j3 >= z3)
      break;
    ret = min(ret, z3 - i3 - j3);
  }
  return ret;
}
int main() {
  for (int i = 1; i < 1120; i++)
    tb[i] = i * i * i;
  for (int i = 1; i < 1120; i++)
    ans[i] = calc(i);
  while (cin >> N, N)
    cout << ans[N] << endl;
}