#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int N;

string dfs(const string& s, int start, int end) {
  string r;
  int i = start;
  int n = 1;

  for (; i <= end; ++i) {
    if ('0' <= s[i] && s[i] <= '9') {
      n = n * 10 + s[i] - '0';
    } else if (s[i] == '(') {
      int cnt = 1;
      int j = i + 1;
      for (; cnt; ++j) {
        if (s[j] == '(') {
          ++cnt;
        } else if (s[j] == ')') {
          --cnt;
        }
      }
      string r0 = dfs(s, i + 1, j - 1);
      r.reserve(r.size() + n * r0.size());
      for (int _ = 0; _ < n; ++_) {
        r += r0;
        if (r.size() > N) {
          return r;
        }
      }
      n = 1;
      i = j;
    } else {
      r.reserve(r.size() + n);
      r += string(n, s[i]);
      n = 1;
    }
  }

  return r;
}

int main() {
  for (;;) {
    string s;
    cin >> s >> N;
    if (s == "0") {
      break;
    }
    string r = dfs(s, 0, s.size() - 1);
    printf("%c\n", r.size() > N ? r[N] : '0');
  }
}