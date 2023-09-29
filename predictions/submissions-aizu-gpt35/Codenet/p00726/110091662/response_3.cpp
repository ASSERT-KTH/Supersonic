#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int MAXN = 1000005;
char r[MAXN];
int idx = 0;
int N;

void dfs(string s, int n, int start) {
  if (idx > N) return;
  if (n == 0) {
    for (int i = start; i < s.size(); i++) {
      if (idx > N) return;
      r[idx++] = s[i];
    }
    return;
  }

  for (int i = start; i < s.size(); i++) {
    if (idx > N) return;
    if (s[i] >= '0' && s[i] <= '9') {
      n = n * 10 + s[i] - '0';
    } else if (s[i] == '(') {
      int j = i + 1, cnt = 1;
      while (cnt != 0) {
        if (s[j] == '(') cnt++;
        if (s[j] == ')') cnt--;
        j++;
      }
      dfs(s, n, i + 1);
      n = 0;
      i = j - 1;
    } else if (s[i] == ')') {
      return;
    } else {
      if (n == 0) n = 1;
      r[idx++] = s[i];
      n--;
    }
  }
}

int main() {
  for (;;) {
    string s;
    cin >> s >> N;
    if (s == "0") break;
    idx = 0;
    dfs(s, 0, 0);
    printf("%c\n", r[N]);
  }
  return 0;
}