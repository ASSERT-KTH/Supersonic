#include <iostream>
using namespace std;

const int MAX_N = 1111;
int tb[MAX_N + 1], ans[MAX_N + 1];

int nr(int a) {
  int low = 1, high = MAX_N, ret = 0;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (tb[mid] <= a) {
      ret = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return tb[ret];
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
  for (int i = 1; i <= MAX_N; i++)
    tb[i] = i * i * i;
  for (int i = 1; i <= MAX_N; i++)
    ans[i] = calc(i);
  int N;
  while (cin >> N, N)
    cout << ans[N] << endl;
}