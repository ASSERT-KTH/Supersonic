#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 1000000;

int N;
char r[MAX_SIZE];

void dfs(const string& s) {
  int r_size = 0;
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
      const string r0 = s.substr(i + 1, j - 1 - i - 1);
      for (int _ = 0; _ < n; _++) {
        int k = 0;
        while (k < r0.size() && r_size < N) {
          r[r_size++] = r0[k++];
        }
        if (r_size > N)
          return;
      }
      n = -1;
      i = j;
    } else {
      if (n < 0)
        n = 1;
      while (n > 0 && r_size < N) {
        r[r_size++] = s[i];
        n--;
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
    if (s == "0")
      break;
    dfs(s);
    printf("%c\n", r_size > N ? r[N] : '0');
  }
}