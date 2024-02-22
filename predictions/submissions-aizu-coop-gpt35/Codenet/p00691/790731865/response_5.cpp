#include <algorithm>
#include <iostream>

using namespace std;

int ans[1112], N;

int nr(int a) {
  int ret = 1;
  for (int i = 2; i < 1112; i++) {
    if (i * i * i > a)
      break;
    ret = i;
  }
  return ret;
}

int calc(int z) {
  int z3 = z * z * z;
  int j3 = nr(z3 - 1);
  int ret = z3 - 1 - j3;
  for (int i = 1; i < z; i++) {
    int i3 = i * i * i;
    if (i3 + j3 >= z3)
      break;
    ret = min(ret, z3 - i3 - j3);
  }
  return ret;
}

int main() {
  int max_cube = nr(1111);
  for (int i = 1; i <= max_cube; i++)
    ans[i] = calc(i);
  while (cin >> N, N)
    cout << ans[N] << endl;
}