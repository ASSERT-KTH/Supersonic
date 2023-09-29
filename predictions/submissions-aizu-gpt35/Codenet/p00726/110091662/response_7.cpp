#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int N;

void dfs(string& s, int& idx, string& r) {
  int i = idx, n = 0;
  for (; i < s.size();) {
    if ('0' <= s[i] && s[i] <= '9') {
      n = n * 10 + s[i] - '0';
      i++;
    } else if (s[i] == '(') {
      int j = i + 1;
      dfs(s, j, r);
      i = j;
    } else if (s[i] == ')') {
      idx = i + 1;
      return;
    } else {
      r += string(n > 0 ? n : 1, s[i]);
      n = 0;
      i++;
    }
  }
  idx = i;
}

int main() {
  for (;;) {
    string s, r;
    cin >> s >> N;
    if (s == "0")
      break;
    int idx = 0;
    dfs(s, idx, r);
    printf("%c\n", r.size() > N ? r[N] : '0');
  }
}