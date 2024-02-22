#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  int n, m;
  unordered_map<int, int> patterns;
  
  while (cin >> n >> m && (n != 0 || m != 0)) {
    patterns.clear();
    
    for (int i = 0; i < n; i++) {
      string b;
      int o;
      cin >> b >> o;
      
      int pattern = 0;
      for (int j = 0; j < 8; j++) {
        pattern <<= 1;
        if (b[j] == '1') {
          pattern |= 1;
        }
      }
      
      patterns[pattern] = o;
    }
    
    int ans = 0;
    for (int i = 0; i < m; i++) {
      string l;
      cin >> l;
      
      int pattern = 0;
      for (int j = 0; j < 8; j++) {
        pattern <<= 1;
        if (l[j] == '1') {
          pattern |= 1;
        }
      }
      
      ans += patterns[pattern];
    }
    
    cout << ans << endl;
  }
  
  return 0;
}