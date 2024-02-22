#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> S(n);
  for (int i = 0; i < n; ++i) {
    cin >> S[i];
  }

  int cnt = 0;
  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    int T;
    cin >> T;

    int left = 0;
    int right = n;
    int mid = (right + left) / 2;

    while (left < right) {
      if (T > S[mid]) {
        left = mid + 1;
      } else if (T < S[mid]) {
        right = mid;
      } else {
        ++cnt;
        break;
      }
      mid = (right + left) / 2;
    }
  }

  cout << cnt << endl;
  return 0;
}