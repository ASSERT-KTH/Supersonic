#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  
  while (n != 0 && m != 0) {
    vector<string> b(n);
    vector<int> o(n);
    
    for (int i = 0; i < n; i++)
      cin >> b[i] >> o[i];
    
    int ans = 0;
    for (int i = 0; i < m; i++) {
      string l;
      cin >> l;
      
      for (int j = 0; j < n; j += 4) {
        bool f1 = true, f2 = true, f3 = true, f4 = true;
        for (int k = 0; k < 8; k += 4) {
          if (b[j][k] != '*' && b[j][k] != l[k]) {
            f1 = false;
            break;
          }
          
          if (b[j + 1][k] != '*' && b[j + 1][k] != l[k]) {
            f2 = false;
            break;
          }
          
          if (b[j + 2][k] != '*' && b[j + 2][k] != l[k]) {
            f3 = false;
            break;
          }
          
          if (b[j + 3][k] != '*' && b[j + 3][k] != l[k]) {
            f4 = false;
            break;
          }
        }
        
        if (f1) {
          ans += o[j];
          break;
        }
        
        if (f2) {
          ans += o[j + 1];
          break;
        }
        
        if (f3) {
          ans += o[j + 2];
          break;
        }
        
        if (f4) {
          ans += o[j + 3];
          break;
        }
      }
    }
    
    cout << ans << endl;
    
    cin >> n >> m;
  }
}