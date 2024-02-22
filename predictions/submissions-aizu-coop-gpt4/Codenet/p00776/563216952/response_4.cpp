#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
using namespace std;

set<string> substrings;
char str[26];
int count[26];

void dfs(int now) {
  if (now == strlen(str)) {
    substrings.insert(string(str));
    return;
  }
  if (str[now] != 'z' && count[str[now] + 1 - 'a'] == 0) {
    str[now] = str[now] + 1;
    dfs(now + 1);
    str[now] = str[now] - 1;
  }
  if (str[now] == 'a' || count[str[now] - 'a'] != 0)
    dfs(now + 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (1) {
    cin >> str;
    if (strcmp(str, "#") == 0)
      break;
    substrings.clear();
    memset(count, 0, sizeof(count));
    dfs(0);
    int num = substrings.size();
    cout << num << endl;
    if (num <= 10) {
      for (const string &substring : substrings) {
        cout << substring << endl;
      }
    } else {
      auto it = substrings.begin();
      rep(i, 0, 5) {
        cout << *it++ << endl;
      }
      it = substrings.end();
      rep(i, 0, 5) {
        cout << *--it << endl;
      }
    }
  }
}