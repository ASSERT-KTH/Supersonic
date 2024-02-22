#include <iostream>
using namespace std;

const int M = 10;

int main() {
  int k;
  while (cin >> k, k) {
    string s, t;
    cin >> s >> t;

    int ans = k;
    int dif[k];

    for (int i = 0; i < k; i++) {
      dif[i] = ((int)(t[i] - s[i]) + M) % M;
    }

    for (int p = 0; p < k; p++) {
      int rot = dif[p];
      if (rot == 0) {
        continue;
      }
      
      int d = 0;
      for (int i = p; i < k; i++) {
        dif[i] = (dif[i] - rot + M) % M;
        d++;
      }
      ans = min(ans, d);
      
      for (int i = p; i < k; i++) {
        dif[i] = (dif[i] + rot) % M;
      }
    }

    cout << ans << endl;
  }
}