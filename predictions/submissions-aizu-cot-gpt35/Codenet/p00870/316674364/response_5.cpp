#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n, m;
  while (cin >> n >> m, n) {
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
      cin >> words[i];
    }

    string text;
    for (int i = 0; i < m; ++i) {
      string word;
      cin >> word;
      text += word;
    }

    int ans = 0;
    for (int j = 0; j < text.size(); ++j) {
      for (int i = 0; i < (1 << n); ++i) {
        bool valid = true;
        for (int k = 0; k < n; ++k) {
          if (!(i & (1 << k)) && words[k].size() + j <= text.size()) {
            int len = words[k].size();
            string substr = text.substr(j, len);
            if (substr != words[k]) {
              valid = false;
              break;
            }
          }
        }
        if (valid) {
          ans++;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}