#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;

int tb[1112], ans[1112], N, cube[1112];

int nr(int a) {
  int ret = 1;
  for (int i = 2; i < 1112; i++) {
    if (tb[i] > a)
      break;
    ret = i;
  }
  return tb[ret];
}

int calc(int z) {
  int z3 = cube[z], ret = z3;
  for (int i = 1; i < z; i++) {
    int i3 = cube[i], j3 = nr(z3 - i3);
    ret = min(ret, z3 - i3 - j3);
  }
  return ret;
}

int main() {
  for (int i = 1; i < 1112; i++) {
    tb[i] = i * i * i;
    cube[i] = i * i * i;
  }
  fill(ans, ans + 1112, INT_MAX);
  for (int i = 1; i < 1112; i++)
    ans[i] = calc(i);
  while (cin >> N, N)
    cout << ans[N] << endl;
}