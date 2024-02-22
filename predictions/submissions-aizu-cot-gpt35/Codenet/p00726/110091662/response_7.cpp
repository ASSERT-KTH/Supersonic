#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int N;

void dfs(const string& s, int start, int end, string& result) {
  int i = start;
  long long n = -1;
  
  for (; i < end;) {
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
      
      dfs(s, i + 1, j - 1, result);
      
      for (int _ = 0; _ < n; _++) {
        if (result.size() + (j - i - 1) > N)
          return;
        result.append(s, i + 1, j - i - 1);
      }
      
      n = -1;
      i = j;
    } else {
      if (n < 0)
        n = 1;
      result.append(n, s[i]);
      n = -1;
      i++;
    }
  }
}

int main() {
  for (;;) {
    string s;
    cin >> s >> N;
    if (s[0] == '0')
      break;
    string result;
    dfs(s, 0, s.size(), result);
    printf("%c\n", result.size() > N ? result[N] : '0');
  }
  return 0;
}