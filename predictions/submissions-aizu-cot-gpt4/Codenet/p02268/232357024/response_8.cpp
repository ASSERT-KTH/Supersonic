#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  
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
    if(binary_search(S.begin(),S.end(),T)) {
        ++cnt;
    }
  }
  cout << cnt << "\n";
  return 0;
}