#include <iostream>
#include <string.h>
using namespace std;
int main() {
  int n, m;
  string output;
  for (;;) {
    cin >> n >> m;
    if (!n && !m)
      break;
    string b[100];
    int o[100];
    int ans = 0;
    for (int i = 0; i < n; i++)
      cin >> b[i] >> o[i];
    for (int i = 0; i < m; i++) {
      string l;
      cin >> l;
      for (int j = 0; j < n; j++) {
        if (b[j] == "*" || b[j] == l) {
          ans += o[j];
          break;
        }
      }
    }
    output += to_string(ans) + "\n";
  }
  cout << output;
}