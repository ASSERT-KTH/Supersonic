#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
  int n, m, o[100];
  string b;
  int ans;
  for (;;) {
    cin >> n >> m;
    if (!n && !m)
      break;
    ans = 0;
    unordered_map<string,int> mp;
    for (int i = 0; i < n; i++){
      cin >> b >> o[i];
      mp[b] = o[i];
    }
    for (int i = 0; i < m; i++) {
      cin >> b;
      if(mp.find(b) != mp.end()){
        ans += mp[b];
      }
    }
    cout << ans << endl;
  }
}