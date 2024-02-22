#include <iostream>
#include <map>
using namespace std;

int main() {
  int n, m;
  map<string, int> o;
  string l;
  int ans;
  while (true) {
    cin >> n >> m;
    if (!n && !m)
      break;
    o.clear();
    ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> l;
      cin >> o[l];
    }
    for (int i = 0; i < m; i++) {
      cin >> l;
      if (o.find(l) != o.end())
        ans += o[l];
    }
    cout << ans << endl;
  }
  return 0;
}