#include <algorithm>
#include <iostream>
using namespace std;

const int N = 1112;
int tb[N], ans[N];

int calc(int z) {
  int z3 = z * z * z;
  int ret = z3;

  for (int i = 1; i < z; i++) {
    int i3 = i * i * i;
    int left = 1, right = N - 1;
    int j3 = 0;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (tb[mid] <= z3 - i3) {
        j3 = tb[mid];
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    if (i3 + j3 >= z3)
      break;

    ret = z3 - i3 - j3;
  }

  return ret;
}

int main() {
  for (int i = 1; i < N; i++)
    tb[i] = i * i * i;

  for (int i = 1; i < N; i++)
    ans[i] = calc(i);

  int n;
  while (cin >> n, n)
    cout << ans[n] << endl;

  return 0;
}