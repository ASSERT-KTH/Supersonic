#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int N;
string dfs(const string& s, int& idx) {
  string r;
  long long n = -1;
  for (; idx < s.size();) {
    if ('0' <= s[idx] && s[idx] <= '9') {
      if (n < 0)
        n = s[idx] - '0';
      else
        n = n * 10 + s[idx] - '0';
      idx++;
    } else if (s[idx] == '(') {
      if (n < 0)
        n = 1;
      int cnt = 1, j = idx + 1;
      for (; cnt;) {
        if (s[j] == '(')
          cnt++;
        else if (s[j] == ')')
          cnt--;
        j++;
      }
      int temp_idx = idx + 1;
      string r0 = dfs(s, temp_idx);
      for (int _ = 0; _ < n; _++) {
        r += r0;
        if (r.size() > N)
          return r;
      }
      n = -1;
      idx = j;
    } else {
      if (n < 0)
        n = 1;
      r += string(n, s[idx]);
      n = -1;
      idx++;
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
    int idx = 0;
    string r = dfs(s, idx);
    printf("%c\n", r.size() > N ? r[N] : '0');
  }
}