#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> S(n);
  unordered_set<int> setS;
  
  for (int i = 0; i < n; ++i) {
    cin >> S[i];
    setS.insert(S[i]);
  }
  
  int cnt = 0;
  int q;
  cin >> q;
  
  for (int i = 0; i < q; ++i) {
    int T;
    cin >> T;
    
    if (setS.count(T) > 0) {
      ++cnt;
    }
  }
  
  cout << cnt << endl;
  
  return 0;
}