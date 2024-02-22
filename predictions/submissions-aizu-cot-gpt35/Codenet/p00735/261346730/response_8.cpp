#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  vector<int> lists;
  for (int i = 2; i <= 300000; i++) {
    bool isPrime = true;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime) {
      if (i % 7 == 1 || i % 7 == 6) {
        lists.push_back(i);
      }
    }
  }

  while (true) {
    int n;
    cin >> n;
    if (n == 1)
      break;
    
    vector<int> ans;
    for (int i = 0; i < lists.size(); i++) {
      if (n % lists[i] == 0) {
        ans.push_back(lists[i]);
      }
    }
    
    cout << n << ':';
    for (int i = 0; i < ans.size(); i++) {
      cout << " " << ans[i];
    }
    cout << endl;
  }
}