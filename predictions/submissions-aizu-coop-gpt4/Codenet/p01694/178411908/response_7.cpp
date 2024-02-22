#include <bits/stdc++.h>
using namespace std;

typedef unordered_map<string, int> umsi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  umsi valid_pairs;
  valid_pairs["lu,ru"] = 1;
  valid_pairs["ru,lu"] = 1;
  valid_pairs["ld,rd"] = 1;
  valid_pairs["rd,ld"] = 1;
  
  int n;
  while (cin >> n, n) {
    int ans = 0;
    string next;
    cin >> next;
    for (int i = 1; i < n; ++i) {
      string temp;
      cin >> temp;
      next += ("," + temp);
      if (valid_pairs.find(next) != valid_pairs.end()) {
        ans += valid_pairs[next];
      }
      next = temp;
    }
    cout << ans << endl;
  }
  return 0;
}