#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  int n, m; 
  unordered_map<string, int> b_map;
  string l, b;
  int o, ans;

  while(true) {
    cin >> n >> m;
    if (!n && !m)
      break;
    ans = 0;
    b_map.clear();
    for(int i = 0; i < n; i++) {
      cin >> b >> o;
      b_map[b] = o;
    }
    for(int i = 0; i < m; i++) {
      cin >> l;
      if(b_map.count(l) > 0) {
        ans += b_map[l];
      }
    }
    cout << ans << endl;
  }
}