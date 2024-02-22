#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;

int main() {
  int n, m, o[100];
  const char* b[100];
  const char l[9];
  int ans;
  for (;;) {
    cin >> n >> m;
    if (!n && !m)
      break;
    ans = 0;
    for (int i = 0; i < n; i++)
      cin >> b[i] >> o[i];
    
    unordered_map<string, int> lookup;
    for (int i = 0; i < n; i++) {
      lookup[b[i]] = o[i];
    }

    for (int i = 0; i < m; i++) {
      cin >> l;
      if (lookup.find(l) != lookup.end()) {
        ans += lookup[l];
      }
    }
    cout << ans << endl;
  }
}