#include <iostream>
#include <vector>
using namespace std;
#define int long long
#define rep2(i, a, b) for (int i = (a); i < (b); i++)
vector<int> lists;
bool checked[300000 + 1] = {};
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  rep2(i, 2, 300000 + 1) {
    if (checked[i])
      continue;
    if (i % 7 == 1 || i % 7 == 6) {
      lists.push_back(i);
      for (int k = i; k <= 300000; k += i) {
        checked[k] = true;
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
      if (n % p == 0) {
        cout << " " << p;
      }
    }
    cout << '\n';
  }
}