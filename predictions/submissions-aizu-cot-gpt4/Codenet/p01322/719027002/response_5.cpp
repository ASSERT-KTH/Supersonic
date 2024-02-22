#include <iostream>
using namespace std;
int main() {
  int n, m, o[100];
  string b[100];
  for (;;) {
    cin >> n >> m;
    if (!n && !m)
      break;
    int ans = 0;
    for (int i = 0; i < n; i++)
      cin >> b[i] >> o[i];
    for (int i = 0; i < m; i++) {
      const string l;
      cin >> l;
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < 8; k++) {
          if (b[j][k] != '*' && b[j][k] != l[k]) {
            continue;
          }
        }
        ans += o[j];
        break;
      }
    }
    cout << ans << endl;
  }
}