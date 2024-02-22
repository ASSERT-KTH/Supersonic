#include <algorithm>
#include <iostream>
using namespace std;
const int MAX_N = 1112;
int tb[MAX_N], ans[MAX_N], N;

void precalculateCubes() {
  for (int i = 1; i < MAX_N; i++)
    tb[i] = i * i * i;
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
  precalculateCubes();
  for (int i = 1; i < MAX_N; i++)
    ans[i] = calc(i);
  while (cin >> N, N)
    cout << ans[N] << endl;
}