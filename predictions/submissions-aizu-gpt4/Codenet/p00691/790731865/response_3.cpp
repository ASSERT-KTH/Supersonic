#include <iostream>
#include <vector>
using namespace std;

vector<int> tb(1112), ans(1112);
int N;

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
  int z3 = z * z * z;
  int ret = z3;
  for (int i = 1; i < z; i++) {
    int i3 = i * i * i, j3 = nr(z3 - i3);
    if (i3 + j3 >= z3)
      break;
    ret = min(ret, z3 - i3 - j3);
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 1; i < 1112; i++)
    tb[i] = i * i * i;
  for (int i = 1; i < 1112; i++)
    ans[i] = calc(i);
  while (cin >> N, N)
    cout << ans[N] << '\n';
}