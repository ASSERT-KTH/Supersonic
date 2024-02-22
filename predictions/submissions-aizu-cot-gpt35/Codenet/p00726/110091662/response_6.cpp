#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int N;

void dfs(const string& s, string& r, int& i) {
  int n = -1;
  while (i < s.size()) {
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
      dfs(s, r, j);
      for (int _ = 0; _ < n; _++) {
        r.reserve(r.size() + r.size() * (j - i));
        r += r.substr(i + 1, j - i - 1);
        if (r.size() > N)
          return;
      }
      n = -1;
      i = j;
    } else {
      if (n < 0)
        n = 1;
      r.reserve(r.size() + n);
      r += string(n, s[i]);
      n = -1;
      i++;
    }
  }
}

int main() {
  for (;;) {
    string s;
    cin >> s >> N;
    if (s == "0")
      break;
    string r;
    dfs(s, r, 0);
    printf("%c\n", r.size() > N ? r[N] : '0');
  }
}