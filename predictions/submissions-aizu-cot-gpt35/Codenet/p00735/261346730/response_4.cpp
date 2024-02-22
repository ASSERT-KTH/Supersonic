#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  const int MAX_NUM = 300000;
  bitset<MAX_NUM + 1> checked;
  vector<int> lists;
  
  for (int i = 2; i <= MAX_NUM; i++) {
    if (checked[i])
      continue;
    if (i % 7 == 1 || i % 7 == 6) {
      lists.push_back(i);
      for (int k = i; k <= MAX_NUM; k += i) {
        checked[k] = true;
      }
    }
  }
  
  while (true) {
    int n;
    cin >> n;
    if (n == 1)
      break;
    vector<int> ans;
    for (auto p : lists) {
      if (n % p == 0) {
        ans.push_back(p);
      }
    }
    cout << n << ':';
    for (int i = 0; i < ans.size(); i++) {
      cout << " " << ans[i];
    }
    cout << endl;
  }
}