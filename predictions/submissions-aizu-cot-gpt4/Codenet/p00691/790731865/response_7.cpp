#include <algorithm>
#include <iostream>
using namespace std;
int tb[1112], ans[1112];

int calc(int z) {
  int z3 = z * z * z, ret = z3;
  for (int i = 1; i < z; i++) {
    int i3 = i * i * i;
    int j3 = *(upper_bound(tb, tb + 1112, z3 - i3) - 1);
    if (i3 + j3 >= z3)
      break;
    ret = min(ret, z3 - i3 - j3);
  }
  return ret;
}

void init() {
  for (int i = 1; i < 1112; i++)
    tb[i] = i * i * i;
  for (int i = 1; i < 1112; i++)
    ans[i] = calc(i);
}

int main() {
  init();
  int N;
  while (cin >> N, N)
    cout << ans[N] << endl;
}