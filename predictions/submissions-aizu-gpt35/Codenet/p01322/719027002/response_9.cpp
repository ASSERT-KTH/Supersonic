#include <iostream>
using namespace std;
int main() {
  int n, m;
  string b[100], l;
  int o[100], ans;
  while(true) {
    cin >> n >> m;
    if (!n && !m) break;
    ans = 0;
    for (int i = 0; i < n; ++i)
      cin >> b[i] >> o[i];
    for (int i = 0; i < m; ++i) {
      cin >> l;
      for (int j = 0; j < n; ++j) {
        bool f = true;
        for (int k = 0; k < 8; ++k) {
          if (b[j][k] != '*' && b[j][k] != l[k]) {
            f = false;
            break;
          }
        }
        if (f) {
          ans += o[j];
          break;
        }
      }
    }
    cout << ans << endl;
  }
}