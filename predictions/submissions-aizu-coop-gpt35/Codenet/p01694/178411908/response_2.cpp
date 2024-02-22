#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  ios_base::sync_with_stdio(false);
  while (cin >> n, n) {
    int ans = 0;
    string now = "", next;
    vector<vector<int>> lookupTable = {
        {0, 1, 0, 0}, // lu ru
        {1, 0, 0, 0}, // ru lu
        {0, 0, 0, 1}, // ld rd
        {0, 0, 1, 0}  // rd ld
    };
    for (int i = 0; i < n; ++i) {
      cin >> next;
      ans += lookupTable[now[0] - 'a'][next[0] - 'a'];
      now = next;
    }
    cout << ans << '\n';
  }
  return 0;
}