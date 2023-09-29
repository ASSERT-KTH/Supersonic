#include <iostream>
using namespace std;
const int MAX_N = 1112;
int tb[MAX_N], ans[MAX_N], N;

inline int nr(int a) {
  int ret = 1;
  for (int i = 2; i < MAX_N && tb[i] <= a; i++) {
    ret = i;
  }
  return tb[ret];
}

inline int calc(int z) {
  int z3 = z * z * z, ret = z3;
  for (int i = 1, i3 = i * i * i; i < z && i3 + tb[2] < z3; i++, i3 = i * i * i) {
    int j3 = nr(z3 - i3);
    if (i3 + j3 >= z3)
      break;
    ret = min(ret, z3 - i3 - j3);
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 1; i < MAX_N; i++)
    tb[i] = i * i * i;
  for (int i = 1; i < MAX_N; i++)
    ans[i] = calc(i);
  while (cin >> N, N)
    cout << ans[N] << '\n';
}