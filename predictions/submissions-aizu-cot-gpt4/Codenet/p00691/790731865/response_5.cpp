#include <algorithm>
#include <iostream>
using namespace std;
int tb[1112], N;

int nr(int a) {
  int left = 1, right = 1111;
  while (left < right) {
    int mid = left + (right - left + 1) / 2;
    if (tb[mid] > a)
      right = mid - 1;
    else
      left = mid;
  }
  return tb[left];
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
  for (int i = 1; i < 1112; i++)
    tb[i] = i * i * i;
  while (cin >> N, N)
    cout << calc(N) << endl;
}