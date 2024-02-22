#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  int n, m;
  unordered_map<string, int> stringToInt;
  string l;
  int ans;

  while (true) {
    cin >> n >> m;
    if (!n && !m)
      break;

    stringToInt.clear();
    ans = 0;

    for (int i = 0; i < n; i++) {
      cin >> l;
      cin >> stringToInt[l];
    }

    for (int i = 0; i < m; i++) {
      cin >> l;
      ans += stringToInt[l];
    }

    cout << ans << endl;
  }

  return 0;
}