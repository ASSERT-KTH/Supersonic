#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  
  while (true) {
    cin >> n >> m;
    
    if (n == 0 && m == 0)
      break;
    
    int ans = 0;
    vector<int> o(n);
    vector<string> b(n);

    for (int i = 0; i < n; i++)
      cin >> b[i] >> o[i];
    
    for (int i = 0; i < m; i++) {
      string l;
      cin >> l;
      bool match = false;
      
      for (int j = 0; j < n; j++) {
        bool f = true;
        
        for (int k = 0; k < 8; k++) {
          if (b[j].substr(k, 1) != "*" && b[j].substr(k, 1) != l.substr(k, 1)) {
            f = false;
            break;
          }
        }
        
        if (f) {
          match = true;
          ans += o[j];
          break;
        }
      }
      
      if (!match)
        ans += 0;
    }
    
    cout << ans << endl;
  }
}