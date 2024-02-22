#include <cstdio>
#include <string>
using namespace std;

int N;
string dfs(const string& s, int& i) {
  string r;
  long long n = -1;
  for (; i < s.size();) {
    if ('0' <= s[i] && s[i] <= '9') {
      if (n < 0) n = s[i] - '0';
      else n = n * 10 + s[i] - '0';
      i++;
    } else if (s[i] == '(') {
      if (n < 0) n = 1;
      int cnt = 1, j = i + 1;
      for (; cnt; j++) {
        if (s[j] == '(') cnt++;
        else if (s[j] == ')') cnt--;
      }
      int tmp = i + 1;
      string r0 = dfs(s, tmp);
      r += string(n, r0[0]);
      n = -1;
      i = j;
    } else {
      if (n < 0) n = 1;
      r += string(n, s[i]);
      n = -1;
      i++;
    }
    if (r.size() > N) break;
  }
  return r;
}

int main() {
  for (;;) {
    char s[100];
    scanf("%s %d", s, &N);
    if (s[0] == '0') break;
    int i = 0;
    string r = dfs(s, i);
    printf("%c\n", r.size() > N ? r[N] : '0');
  }
  return 0;
}