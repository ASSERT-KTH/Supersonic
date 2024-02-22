#include <iostream>
#include <string>
#include <unordered_map>
#include <cstring>
using namespace std;

int main() {
  int n, m;
  unordered_map<string, int> mapping;
  
  while (cin >> n >> m && (n || m)) {
    mapping.clear();
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
      string b;
      int o;
      cin >> b >> o;
      mapping[b] = o;
    }
    
    for (int i = 0; i < m; i++) {
      string l;
      cin >> l;
      
      for (auto& it : mapping) {
        if (strncmp(it.first.c_str(), l.c_str(), 8) == 0) {
          ans += it.second;
          break;
        }
      }
    }
    
    cout << ans << endl;
  }
  
  return 0;
}