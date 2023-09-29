#include <iostream>
#include <vector>
using namespace std;
#define int long long
#define rep2(i, a, b) for (int i = (a); i < (b); i++)
vector<int> lists;
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  bool checked[300000 + 1] = {};
  rep2(i, 2, 300000 + 1) {
    if (checked[i])
      continue;
    if (i % 7 == 1 || i % 7 == 6) {
      lists.push_back(i);
      for(int j = i; j <= 300000; j+=i) {
        checked[j] = true;
      }
    }
  }
  while (true) {
    int n;
    cin >> n;
    if (n == 1)
      break;
    for (auto p : lists) {
      if (n % p == 0) {
        cout << " " << p;
      }
    }
    cout << '\n';
  }
}