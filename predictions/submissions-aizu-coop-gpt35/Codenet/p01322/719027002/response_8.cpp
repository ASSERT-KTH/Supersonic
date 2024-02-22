#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
  int n, m;
  string l;
  int ans;

  while (true) {
    cin >> n >> m;
    if (n == 0 && m == 0)
      break;

    ans = 0;
    vector<string> b(n);
    unordered_map<string, int> o;

    for (int i = 0; i < n; i++) {
      cin >> b[i] >> o[b[i]];
    }

    for (int i = 0; i < m; i++) {
      cin >> l;
      if (o.count(l)) {
        ans += o[l];
      }
    }

    cout << ans << endl;
  }
  return 0;
}