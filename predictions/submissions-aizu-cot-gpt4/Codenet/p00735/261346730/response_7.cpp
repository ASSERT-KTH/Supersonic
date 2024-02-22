#include <iostream>
#include <vector>
using namespace std;
#define int long long
#define rep2(i, a, b) for (int i = (a); i < (b); i++)
const int INF = 1 << 30;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> lists;
  rep2(i, 2, 300000 + 1) {
    if (i % 7 == 1 || i % 7 == 6) {
      lists.push_back(i);
      for (int k = i*2; k <= 300000; k += i) {
        lists.push_back(k);
      }
    }
  }
  while (true) {
    int n;
    cin >> n;
    if (n == 1)
      break;
    cout << n << ':';
    for(auto p : lists) {
      if(p > n) 
        break;
      if (n % p == 0) {
        cout << " " << p;
      }
    }
    cout << endl;
  }
}