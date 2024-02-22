#include <algorithm>
#include <iostream>
using namespace std;
int tb[1112], ans[1112], N;

int calc(int z) {
  int z3 = tb[z], ret = z3;
  for (int i = 1; i < z; i++) {
    int i3 = tb[i], j3 = *lower_bound(tb, tb + N, z3 - i3);
    if (i3 + j3 >= z3)
      break;
    ret = min(ret, z3 - i3 - j3);
  }
  return ret;
}

int main() {
  for (int i = 1; i < 1112; i++) {
    tb[i] = i * i * i;
    ans[i] = calc(i);
  }
  while (cin >> N, N)
    cout << ans[N] << endl;
}