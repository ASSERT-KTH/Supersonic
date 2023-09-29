#include <iostream>
using namespace std;

int tb[1112], ans[1112];

inline int nr(int a) {
  int ret = 1;
  for (int i = 2; i < 1112 && tb[i] <= a; i++)
    ret = i;
  return tb[ret];
}

inline int calc(int z) {
  int z3 = z * z * z, ret = z3;
  for (int i = 1, i3 = i * i * i, j3; i < z && (j3 = nr(z3 - i3)) + i3 < z3; i++, i3 = i * i * i)
    ret = min(ret, z3 - i3 - j3);
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  for (int i = 1; i < 1112; i++)
    tb[i] = i * i * i;
    
  for (int i = 1; i < 1112; i++)
    ans[i] = calc(i);
    
  int N;
  while (cin >> N, N)
    cout << ans[N] << '\n';
}