#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
  int n, m, o[100];
  string b[100];
  string l;
  int ans;
  for (;;) {
    cin >> n >> m;
    if (!n && !m)
      break;
    ans = 0;
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++) {
      cin >> b[i] >> o[i];
      mp[b[i]] = o[i];
    }
    for (int i = 0; i < m; i++) {
      cin >> l;
      if (mp.find(l) != mp.end()) {
        ans += mp[l];
      }
    }
    cout << ans << endl;
  }
}