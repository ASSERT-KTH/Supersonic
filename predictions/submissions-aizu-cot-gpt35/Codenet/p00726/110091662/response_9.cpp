#include <iostream>
#include <string>

using namespace std;

string dfs(const string& s, int start, int end, int N) {
  string r;
  int i = start;
  long long n = -1;
  
  while (i <= end) {
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
      while (cnt) {
        if (s[j] == '(')
          cnt++;
        else if (s[j] == ')')
          cnt--;
        j++;
      }
      string r0 = dfs(s, i + 1, j - 1, N);
      for (int _ = 0; _ < n; _++) {
        r.append(r0);
        if (r.size() > N)
          return r;
      }
      n = -1;
      i = j;
    } else {
      if (n < 0)
        n = 1;
      r.append(n, s[i]);
      n = -1;
      i++;
    }
  }
  
  return r;
}

int main() {
  for (;;) {
    string s;
    cin >> s;
    if (s == "0")
      break;
    int N;
    cin >> N;
    string r = dfs(s, 0, s.size() - 1, N);
    cout << (r.size() > N ? r[N] : '0') << '\n';
  }
  return 0;
}