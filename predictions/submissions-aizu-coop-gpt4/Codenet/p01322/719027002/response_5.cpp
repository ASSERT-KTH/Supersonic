#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  int n, m, ans;
  string l, key;
  map<string, int> dict;

  while (true) {
    cin >> n >> m;
    if (!n && !m)
      break;
    ans = 0;
    dict.clear();

    for (int i = 0; i < n; i++) {
      cin >> key;
      cin >> dict[key];
    }

    for (int i = 0; i < m; i++) {
      cin >> l;
      for (auto it = dict.begin(); it != dict.end(); it++) {
        string temp = it->first;
        for (int j = 0; j < 8; j++) {
          if (temp[j] != '*' && temp[j] != l[j]) {
            temp[j] = l[j];
          }
        }
        if (temp == it->first) {
          ans += it->second;
          break;
        }
      }
    }

    cout << ans << endl;
  }

  return 0;
}