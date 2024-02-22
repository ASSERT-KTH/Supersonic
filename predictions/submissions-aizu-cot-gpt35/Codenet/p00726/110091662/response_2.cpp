#include <iostream>
#include <string>

using std::string;

string dfs(string s) {
  string r;
  int i = 0;
  int n = -1;
  int size = s.size();

  for (int i = 0; i < size;) {
    if ('0' <= s[i] && s[i] <= '9') {
      if (n < 0)
        n = s[i] - '0';
      else
        n = n * 10 + s[i] - '0';
      ++i;
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
      string r0 = dfs(s.substr(i + 1, j - 1 - i - 1));
      r.reserve(r.size() + n * r0.size());
      for (int _ = 0; _ < n; _++) {
        r += r0;
        if (r.size() > N)
          return r;
      }
      n = -1;
      i = j;
    } else {
      if (n < 0)
        n = 1;
      r.reserve(r.size() + n);
      for (int _ = 0; _ < n; _++) {
        r += s[i];
        if (r.size() > N)
          return r;
      }
      n = -1;
      ++i;
    }
  }
  return r;
}

int main() {
  for (;;) {
    string s;
    int N;
    cin >> s >> N;
    if (s == "0")
      break;
    string r = dfs(s);
    printf("%c\n", r.size() > N ? r[N] : '0');
  }
}