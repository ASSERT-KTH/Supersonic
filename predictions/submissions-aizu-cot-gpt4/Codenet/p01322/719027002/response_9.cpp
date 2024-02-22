#include <iostream>
using namespace std;
int main() {
  int n, m, o[100];
  string b[100];
  string l;
  int ans;
  for (;;) {
    cin >> n >> m;
    if (!n && !m)
      break;
    ans = 0;
    for (int i = 0; i < n; i++)
      cin >> b[i] >> o[i];
    for (int i = 0; i < m; i++) {
      cin >> l;
      for (int j = 0; j < n; j++) {
        if (b[j].substr(0, 8) == l.substr(0, 8)) {
          ans += o[j];
          break;
        }
      }
    }
    cout << ans << endl;
  }
}