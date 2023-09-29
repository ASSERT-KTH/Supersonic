#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int M = 10;

int main() {
  int k;
  while (cin >> k, k) {
    string s, t;
    cin >> s >> t;
    vector<int> dif(k);
    for (int i = 0; i < k; i++) {
      dif[i] = ((int)(t[i] - s[i]) + M) % M;
    }
    sort(dif.begin(), dif.end());
    int ans = dif.back();
    for(int i = dif.size()-2; i >= 0; i--) {
      if(dif[i] == dif[i+1]) {
        ans--;
      } else {
        break;
      }
    }
    cout << ans << endl;
  }
}