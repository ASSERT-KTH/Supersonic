#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
const int MAX_N = 1e7;
int N, idx;
char r[MAX_N+2];
string dfs(string s) {
  int i = 0;
  long long n = -1;
  for (; i < s.size();) {
    if ('0' <= s[i] && s[i] <= '9') {
      if (n < 0) n = s[i] - '0';
      else n = n * 10 + s[i] - '0';
      i++;
    } else if (s[i] == '(') {
      if (n < 0) n = 1;
      int cnt = 1, j = i + 1;
      for (; cnt;) {
        if (s[j] == '(') cnt++;
        else if (s[j] == ')') cnt--;
        j++;
      }
      string r0 = dfs(s.substr(i + 1, j - 1 - i - 1));
      for (int _ = 0; _ < n; _++) {
        for (char c : r0) {
          if (idx > N) return "";
          r[++idx] = c;
        }
      }
      n = -1;
      i = j;
    } else {
      if (n < 0) n = 1;
      for (int j = 0; j < n; j++) {
        if (idx > N) return "";
        r[++idx] = s[i];
      }
      n = -1;
      i++;
    }
  }
  return "";
}
int main() {
  for (;;) {
    string s;
    cin >> s >> N;
    if (s == "0") break;
    idx = 0;
    dfs(s);
    printf("%c\n", r[N]);
  }
}