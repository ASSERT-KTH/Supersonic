#include <iostream>
#include <algorithm>
using namespace std;
int tb[1112], ans[1112], N;
int nr(int a) {
  int ret = 1;
  while(tb[ret+1] <= a && ret < 1111) ret++;
  return tb[ret];
}
int calc(int z) {
  int z3 = z * z * z, ret = z3;
  for (int i = 1, i3 = i * i * i; i3 < z3; i++, i3 = i * i * i) {
    int j3 = nr(z3 - i3);
    if (i3 + j3 >= z3)
      break;
    ret = min(ret, z3 - i3 - j3);
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 1; i < 1112; i++)
    tb[i] = i * i * i;
  for (int i = 1; i < 1112; i++)
    ans[i] = calc(i);
  while (cin >> N, N)
    cout << ans[N] << '\n';
}