#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const int MAXN = 1112;
int tb[MAXN], ans[MAXN], N;

int nr(int a) {
  int left = 0, right = MAXN, mid;
  while (left < right) {
    mid = left + (right - left) / 2;
    if (tb[mid] <= a)
      left = mid + 1;
    else
      right = mid;
  }
  return tb[left - 1];
}

int calc(int z) {
  int z3 = z * z * z, ret = z3;
  for (int i = 1, i3 = i * i * i; i3 < z3; i++, i3 = i * i * i) {
    int j3 = nr(z3 - i3);
    if (i3 + j3 >= z3)
      break;
    ret = min(ret, z3 - i3 - j3);
  }
  return ret;
}

int main() {
  for (int i = 1; i < MAXN; i++)
    tb[i] = i * i * i;
  for (int i = 1; i < MAXN; i++)
    ans[i] = calc(i);
  while (cin >> N, N)
    cout << ans[N] << endl;
}