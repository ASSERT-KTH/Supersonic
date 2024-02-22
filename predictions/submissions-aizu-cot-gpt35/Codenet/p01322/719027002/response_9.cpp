#include <iostream>
#include <string>
using namespace std;

int main() {
  int n, m;
  string b[100];
  int o[100];
  string l;
  
  while (cin >> n >> m && n != 0 && m != 0) {
    int ans = 0;
    
    for (int productIndex = 0; productIndex < n; productIndex++)
      cin >> b[productIndex] >> o[productIndex];
    
    for (int brandIndex = 0; brandIndex < m; brandIndex++) {
      cin >> l;
      
      for (int characterIndex = 0; characterIndex < l.length(); characterIndex++) {
        if (b[brandIndex][characterIndex] != l[characterIndex]) {
          ans += o[brandIndex];
          break;
        }
      }
    }
    
    cout << ans << endl;
  }
  return 0;
}