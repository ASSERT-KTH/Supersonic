#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<int> S(n);
  for (int i = 0; i < n; ++i) {
    cin >> S[i];
  }
  
  int cnt = 0;
  int q;
  cin >> q;
  
  for (int i = 0; i < q; ++i) {
    int T;
    cin >> T;
    
    int left = 0;
    int right = n;
    
    while (left < right) {
      int mid = (right + left) / 2;
      
      if (T == S[mid]) {
        ++cnt;
        break;
      } else if (T > S[mid]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
  }
  
  cout << cnt << endl;
  return 0;
}