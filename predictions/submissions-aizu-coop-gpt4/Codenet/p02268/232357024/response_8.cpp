#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int> S(n);
  for (auto& num : S) {
    cin >> num;
  }

  int cnt = 0;
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int T;
    cin >> T;

    int left = 0, right = n;
    while (left < right) {
      int mid = left + ((right - left) >> 1);
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

  cout << cnt << '\n';
  return 0;
}