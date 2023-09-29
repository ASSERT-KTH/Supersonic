#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1112;
vector<int> tb(MAX), ans(MAX);
int N;

inline int calc(int z) {
  int z3 = z * z * z, ret = z3;
  for (int i = 1, i3; i < z && (i3 = i * i * i) + tb[z - i] >= z3; ++i)
    ret = min(ret, z3 - i3 - tb[z - i]);
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  for (int i = 1; i < MAX; ++i)
    tb[i] = i * i * i;
  for (int i = 1; i < MAX; ++i)
    ans[i] = calc(i);
  while (cin >> N, N)
    cout << ans[N] << '\n';
}