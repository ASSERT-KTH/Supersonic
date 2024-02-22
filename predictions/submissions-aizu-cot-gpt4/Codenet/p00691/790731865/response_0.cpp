#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int tb[1112], ans[1112], N;

int nr(int a) {
  int ret = cbrt(a);  // Use in-built function to calculate cube root
  return tb[ret];
}

int calc(int z) {
  int z3 = z * z * z, ret = z3;
  int i3 = 1;
  for (int i = 1; i < z; i++) {
    int j3 = nr(z3 - i3);
    int sum = i3 + j3;
    if (sum >= z3)
      break;
    ret = min(ret, z3 - sum);
    i3 += (3*i*i + 3*i + 1);  // Calculate the next cube
  }
  return ret;
}

int main() {
  for (int i = 1; i < 1112; i++)
    tb[i] = i * i * i;
  for (int i = 1; i < 1112; i++)
    ans[i] = calc(i);
  while (cin >> N, N)
    cout << ans[N] << endl;
}