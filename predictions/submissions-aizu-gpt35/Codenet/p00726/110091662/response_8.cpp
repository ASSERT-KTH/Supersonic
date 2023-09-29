#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int MAX_N = 1e7 + 5;
int N;
char r[MAX_N];
int len;

void dfs(string s, int& p) {
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
      dfs(s.substr(i + 1, j - 1 - i - 1), p);
      if (p >= N) return;
      while (n--) {
        for (int k = i + 1; k < j - 1; k++) {
          r[len++] = s[k];
          if (len >= N) return;
        }
      }
      n = -1;
      i = j;
    } else {
      if (n < 0) n = 1;
      while (n--) {
        r[len++] = s[i];
        if (len >= N) return;
      }
      n = -1;
      i++;
    }
  }
}

int main() {
  for (;;) {
    string s;
    cin >> s >> N;
    if (s == "0") break;
    len = 0;
    dfs(s, len);
    printf("%c\n", len >= N ? r[N] : '0');
  }
}