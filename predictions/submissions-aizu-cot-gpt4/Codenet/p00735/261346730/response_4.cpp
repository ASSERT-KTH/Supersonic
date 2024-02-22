#include <iostream>
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  bool checked[300001] = {};
  for (int i = 2; i <= 300000; i++) {
    if (checked[i])
      continue;
    if (i % 7 == 1 || i % 7 == 6) {
      int k = 1;
      while (i * k <= 300000) {
        checked[i * k] = true;
        k++;
      }
    }
  }
  while (true) {
    int n;
    cin >> n;
    if (n == 1)
      break;
    cout << n << ':';
    for (int i = 2; i <= n; i++) {
      if (!checked[i] && (i % 7 == 1 || i % 7 == 6)) {
        cout << " " << i;
      }
    }
    cout << '\n';
  }
}