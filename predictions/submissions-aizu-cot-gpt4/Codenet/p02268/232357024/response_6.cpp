#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int S[n];
  for (int i = 0; i < n; ++i) {
    cin >> S[i];
  }
  int cnt = 0, q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int T;
    cin >> T;
    int left = 0, right = n;
    while (left < right) {
      int mid = (right + left) / 2;
      if (T > S[mid]) {
        left = mid + 1;
      } else if (T < S[mid]) {
        right = mid;
      } else {
        ++cnt;
        break;
      }
    }
  }
  printf("%d\n", cnt);
  return 0;
}