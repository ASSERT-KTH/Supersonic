#include <iostream>
#include <vector>
using namespace std;
#define int long long
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<int> lists;
  bool checked[300000 + 1] = {};
  // equivalent to rep2(i, 2, 300000 + 1)
  for(int i = 2; i < 300001; i++) {
    if (checked[i])
      continue;
    if (i % 7 == 1 || i % 7 == 6) {
      lists.push_back(i);
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
    for (auto p : lists) {
      if (p > n)
        break;
      if (n % p == 0) {
        cout << " " << p;
      }
    }
    cout << endl;
  }
}