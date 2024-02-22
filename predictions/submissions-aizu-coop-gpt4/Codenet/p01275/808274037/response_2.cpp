#include <iostream>
#include <string>
using namespace std;

const int M = 10;

int main() {
  int k;
  while (cin >> k, k) {
    string s, t;
    cin >> s >> t;
    int ans = k;
    for (int p = 0; p < k; p++) {
      int d = 0;
      int rot = ((int)(t[p] - s[p]) + M) % M;
      if (rot == 0) {
        d++;
        continue;
      }
      d++;
      for (int i = p; i < k; i++) {
        rot = ((int)(t[i] - s[i]) - rot + M) % M;
      }
      d++;
      for (int i = p; i < k; i++) {
        rot = ((int)(t[i] - s[i]) + rot + M) % M;
      }
      if (d < ans) {
        ans = d;
      }
    }
    cout << ans << endl;
  }
  return 0;
}