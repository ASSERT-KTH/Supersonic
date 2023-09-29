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
      if (n < 0)
        n = s[i] - '0';
      else
        n = n * 10 + s[i] - '0';
      i++;
    } else if (s[i] == '(') {
      if (n < 0)
        n = 1;
      int cnt = 1, j = i + 1;
      for (; cnt;) {
        if (s[j] == '(')
          cnt++;
        else if (s[j] == ')')
          cnt--;
        j++;
      }
      int ti = i + 1;
      string r0 = dfs(s, ti);
      for (int _ = 0; _ < n && r.size() <= N; _++) {
        r += r0;
      }
      n = -1;
      i = j;
    } else {
      if (n < 0)
        n = 1;
      r += string(min(n, (long long)N - r.size() + 1), s[i]);
      n = -1;
      i++;
    }
    if (r.size() > N)
      return r;
  }
  return r;
}
int main() {
  for (;;) {
    string s;
    cin >> s >> N;
    if (s == "0")
      break;
    int i = 0;
    string r = dfs(s, i);
    printf("%c\n", r.size() > N ? r[N] : '0');
  }
}