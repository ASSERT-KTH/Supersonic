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
      for (; cnt;) {
        if (s[j] == '(')
          cnt++;
        else if (s[j] == ')')
          cnt--;
        j++;
      }
      string r0 = dfs(s.substr(i + 1, j - 1 - i - 1));
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
      r += string(n, s[i]);
      n = -1;
      i++;
    }
