#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int N;
void dfs(string &s, int l, int r, string &out) {
  long long n = -1;
  for (int i = l; i < r; i++) {
    if ('0' <= s[i] && s[i] <= '9') {
      if (n < 0)
        n = s[i] - '0';
      else
        n = n * 10 + s[i] - '0';
    } else if (s[i] == '(') {
      if (n < 0)
        n = 1;
      int cnt = 1, j = i + 1;
      for (; cnt; j++) {
        if (s[j] == '(')
          cnt++;
        else if (s[j] == ')')
          cnt--;
      }
      string r0;
      dfs(s, i + 1, j - 1, r0);
      for (int _ = 0; _ < n; _++) {
        for (char c : r0) {
          out.push_back(c);
          if (out.size() > N)
            return;
        }
      }
      n = -1;
      i = j;
    } else {
      if (n < 0)
        n = 1;
      out += string(n, s[i]);
      n = -1;
    }
  }
}
int main() {
  while (true) {
    string s;
    cin >> s >> N;
    if (s == "0")
      break;
    string r;
    dfs(s, 0, s.size(), r);
    cout << (r.size() > N ? r[N] : '0') << '\n';
  }
  return 0;
}