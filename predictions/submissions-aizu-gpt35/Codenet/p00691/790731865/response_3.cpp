#include <algorithm>
#include <iostream>
using namespace std;
int tb[1112], ans[1112], N;
int nr(int a) {
  int ret = 1;
  for (int i = 2; i < 112; i++) {
    if (tb[i] > a)
      break;
    ret = i;
  }
  return tb[ret];
}
int calc(int z) {
  int ret = z*z*z;
  for (int i = 1; i < z; i++) {
    int i3 = i * i * i, j3 = nr(z*z*z - i3);
    if (i3 + j3 >= ret)
      break;
    ret = i3 + j3;
  }
  return ret;
}
int main() {
  for (int i = 1; i < 112; i++)
    tb[i] = i * i * i;
  for (int i = 1; i < 112; i++)
    ans[i] = calc(i);
  while (cin >> N, N)
    cout << ans[N] << endl;
}