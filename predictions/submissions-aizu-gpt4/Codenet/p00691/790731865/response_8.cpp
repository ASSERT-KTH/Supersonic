#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 1112;

int tb[MAX], ans[MAX], N;

inline int nr(int a) {
  int ret = 1;
  for (int i = 2; i < MAX; i++) {
    if (tb[i] > a)
      break;
    ret = i;
  }
  return tb[ret];
}

inline int calc(int z) {
  int z3 = z * z * z, ret = z3;
  int sqrt_z3 = sqrt(z3);
  for (int i = 1; i <= sqrt_z3; i++) {
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

  for (int i = 1; i < MAX; i++)
    tb[i] = i * i * i;
  for (int i = 1; i < MAX; i++)
    ans[i] = calc(i);
  while (cin >> N)
    if(N)
      cout << ans[N] << '\n';
}
