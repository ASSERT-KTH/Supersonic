#include <algorithm>
#include <iostream>
using namespace std;
int tb[1112], ans[1112], N;

// Binary search to find the largest i such that tb[i] <= a
int nr(int a) {
  int low = 2, high = 1111, mid;
  while (low <= high) {
    mid = low + (high - low) / 2;
    if (tb[mid] <= a)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return tb[high];
}

int calc(int z) {
  int z3 = z * z * z, ret = z3;
  int i3 = 1, j3;
  for (int i = 1; i < z; i++, i3 += 3*i*i) {
    j3 = nr(z3 - i3);
    if (i3 + j3 >= z3)
      break;
    ret = min(ret, z3 - i3 - j3);
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