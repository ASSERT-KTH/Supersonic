#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int N;
vector<char> dfs(const vector<char>& s, int i, int j) {
  vector<char> r;
  long long n = -1;
  while (i < j) {
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
      while (cnt) {
        if (s[k] == '(')
          cnt++;
        else if (s[k] == ')')
          cnt--;
        k++;
      }
      vector<char> r0 = dfs(s, i + 1, k - 1);
      for (int _ = 0; _ < n; _++) {
        r.insert(r.end(), r0.begin(), r0.end());
        if (r.size() > N)
          return r;
      }
      n = -1;
      i = k;
    } else {
      if (n < 0)
        n = 1;
      r.insert(r.end(), n, s[i]);
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
    vector<char> r = dfs(vector<char>(s.begin(), s.end()), 0, s.size());
    printf("%c\n", r.size() > N ? r[N] : '0');
  }
}