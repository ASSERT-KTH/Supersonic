#include <iostream>
using namespace std;

int main() {
  size_t n;
  cin >> n;
  int S[n];
  for (size_t i = 0; i < n; ++i) {
    cin >> S[i];
  }
  int cnt = 0;
  size_t q;
  cin >> q;
  for (size_t i = 0; i < q; ++i) {
    int T;
    cin >> T;
    size_t left = 0;
    size_t right = n;
    while (left < right) {
      size_t mid = (right + left) / 2;
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
  cout << cnt << endl;
  return 0;
}