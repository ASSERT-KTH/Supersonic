#include <algorithm>
#include <iostream>
using namespace std;
int ans[1112], N;

int nr(int a) {
  int i = 1;
  while (true) {
    int i3 = i * i * i;
    if (i3 > a)
      break;
    i++;
  }
  return (i - 1) * (i - 1) * (i - 1);
}

int calc(int z) {
  int z3 = z * z * z, ret = z3;
  int j3 = nr(z3);
  for (int i = z; i > 0; i--) {
    int i3 = i * i * i;
    if (i3 + j3 >= z3)
      break;
    ret = min(ret, z3 - i3 - j3);
  }
  return ret;
}

int main() {
  for (int i = 1; i < 1112; i++)
    ans[i] = calc(i);
  while (cin >> N, N)
    cout << ans[N] << endl;
}