#include <iostream>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  while (n || m) {
    int* o = new int[n];
    string* b = new string[n];
    for (int i = 0; i < n; i++)
      cin >> b[i] >> o[i];
    int ans = 0;
    for (int i = 0; i < m; i++) {
      string l;
      cin >> l;
      for (int j = 0; j < n; j++) {
        bool f = true;
        for (int k = 0; k < 8; k++) {
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
    delete[] o;
    delete[] b;
    cin >> n >> m;
  }
}