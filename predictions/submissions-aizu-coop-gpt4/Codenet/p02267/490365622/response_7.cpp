#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  int n, q, cnt = 0;
  unordered_set<int> S;
  
  cin >> n;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    S.insert(tmp);
  }
  
  cin >> q;
  for (int i = 0; i < q; i++) {
    int tmp;
    cin >> tmp;
    if (S.find(tmp) != S.end())
      cnt++;
  }
  
  cout << cnt << endl;
  return 0;
}