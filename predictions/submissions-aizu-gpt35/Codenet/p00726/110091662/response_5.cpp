#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int N;
string dfs(string s) {
  string r;
  int i = 0;
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
      for (; cnt; j++) {
        cnt += s[j] == '(';
        cnt -= s[j] == ')';
      }
      string r0 = dfs(s.substr(i + 1, j - 2 - i));
      if (N < r.size() + r0.size() * n) {
        r += r0.substr(0, (N - r.size()) / n);
        return r;
      }
      for (int _ = 0; _ < n; _++) {
        r += r0;
      }
      n = -1;
      i = j;
    } else {
      if (n < 0)
        n = 1;
      if (N < r.size() + n) {
        r += string(1, s[i + N - r.size() - 1]);
        return r;
      }
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
    string r = dfs(s);
    printf("%c\n", r[N]);
  }
}