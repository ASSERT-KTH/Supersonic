#include <iostream>
#include <cstring>
#include <algorithm>
#define rep(i, a, n) for (int i = a; i < n; i++)
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  char s[11];
  while (1) {
    cin >> s;
    if (strcmp(s, "#") == 0)
      break;
    int len = strlen(s);
    sort(s, s + len);
    cout << len << endl;
    rep(i, 0, len) { cout << s[i] << endl; }
    if (len > 10) {
      rep(i, 0, 5) { cout << s[i] << endl; }
      rep(i, len - 5, len) { cout << s[i] << endl; }
    }
  }
}