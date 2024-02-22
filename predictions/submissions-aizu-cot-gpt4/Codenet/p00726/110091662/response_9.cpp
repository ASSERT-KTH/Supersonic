#include <iostream>
#include <string>
using namespace std;
int N, len;
string dfs(const string& s, int i, int j) {
  string r;
  long long n = -1;
  for (; i < j;) {
    if ('0' <= s[i] && s[i] <= '9') {
      if (n < 0)
        n = s[i] - '0';
      else
        n = n * 10 + s[i] - '0';
      i++;
    } else if (s[i] == '(') {
      if (n < 0)
        n = 1;
      int cnt = 1, k = i + 1;
      for (; cnt;) {
        if (s[k] == '(')
          cnt++;
        else if (s[k] == ')')
          cnt--;
        k++;
      }
      string r0 = dfs(s, i + 1, k - 1);
      for (int _ = 0; _ < n; _++) {
        r += r0;
        if (r.size() > N)
          return r;
      }
      n = -1;
      i = k;
    } else {
      if (n < 0)
        n = 1;
      for(int _ = 0; _ < n; _++){
        r += s[i];
        if (r.size() > N)
          return r;
      }
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
    string r = dfs(s, 0, s.size());
    printf("%c\n", r.size() > N ? r[N] : '0');
  }
}