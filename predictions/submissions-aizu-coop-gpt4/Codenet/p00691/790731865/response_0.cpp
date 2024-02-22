#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

map<int, int> tb;
int ans[1112], N;

int nr(int a) {
  auto it = tb.upper_bound(a);
  --it;
  return it->second;
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
  std::ios::sync_with_stdio(false); cin.tie(0);
  
  for (int i = 1; i < 1112; i++)
    tb[i * i * i] = i * i * i;
  
  for (int i = 1; i < 1112; i++)
    ans[i] = calc(i);
  
  while (cin >> N, N)
    cout << ans[N] << "\n";
}