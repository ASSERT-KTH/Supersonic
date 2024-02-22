#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
    
  int n, q, cnt = 0;
  unordered_set<int> S;

  cin >> n;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    S.insert(temp);
  }

  cin >> q;
  for (int j = 0; j < q; j++) {
    int temp;
    cin >> temp;
    if (S.find(temp) != S.end()) {
      cnt++;
    }
  }
  
  cout << cnt << "\n";
  return 0;
}