#include <bits/stdc++.h>
#define debug(x) cout << #x << " : " << (x) << " --------------" << endl;
using namespace std;

int binary_search(int z, int e) {
  int left = 0, right = sqrt(e - z*z*z);
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (z*z*z + mid*mid <= e) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return right;
}

int main(void) {
  int e;
  while (cin >> e, e) {
    int m = 1000000;
    for (int z = 100; z >= 0; --z) {
      int val = z * z * z;
      if (val > e) {
        break;
      }
      int y = binary_search(z, e);
      int val2 = val + y * y;
      m = min(m, (e - val2) + y + z);
    }
    cout << m << endl;
  }
  return EXIT_SUCCESS;
}