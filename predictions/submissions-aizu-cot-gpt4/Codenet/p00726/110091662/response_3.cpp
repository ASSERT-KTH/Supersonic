#include <iostream>
#include <string>
using namespace std;

int N;

string dfs(const string& s, int start, int end) {
  string r;
  r.reserve(N + 1);
  int i = start;
  long long n = -1;
  for (; i < end; ++i) {
    if ('0' <= s[i] && s[i] <= '9') {
      n = (n < 0 ? s[i] - '0' : n * 10 + s[i] - '0');
    } else if (s[i] == '(') {
      if (n < 0)
        n = 1;
      int cnt = 1, j = i + 1;
      for (; cnt; ++j) {
        cnt += (s[j] == '(' ? 1 : (s[j] == ')' ? -1 : 0));
      }
      string r0 = dfs(s, i + 1, j - 1);
      for (int _ = 0; _ < n && r.size() <= N; ++_) {
        r += r0;
      }
      n = -1;
      i = j;
    } else {
      if (n < 0)
        n = 1;
      r.append(n, s[i]);
      n = -1;
    }
  }
  return r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (;;) {
    string s;
    cin >> s >> N;
    if (s == "0")
      break;
    string r = dfs(s, 0, s.size());
    cout << (r.size() > N ? r[N] : '0') << '\n';
  }
}