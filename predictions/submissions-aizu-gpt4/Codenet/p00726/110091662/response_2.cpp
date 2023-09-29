#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int N;
string dfs(string &s, int &i) {
  string r;
  long long n = -1;
  for (; i < s.size();) {
    if ('0' <= s[i] && s[i] <= '9') {
      n = (n < 0) ? s[i] - '0' : n * 10 + s[i] - '0';
      i++;
    } else if (s[i] == '(') {
      n = (n < 0) ? 1 : n;
      int cnt = 1, j = ++i;
      for (; cnt; ++j) {
        if (s[j] == '(')
          cnt++;
        else if (s[j] == ')')
          cnt--;
      }
      string r0 = dfs(s, i);
      for (int _ = 0; _ < n; _++) {
        r += r0;
        if (r.size() > N)
          return r;
      }
      n = -1;
      i = j;
    } else {
      n = (n < 0) ? 1 : n;
      r += string(n, s[i]);
      n = -1;
      i++;
    }
  }
  return r;
}
int main() {
  for (;;) {
    string s;
    cin >> s >> N;
    if (s == "0")
      break;
    int start = 0;
    string r = dfs(s, start);
    printf("%c\n", r.size() > N ? r[N] : '0');
  }
}