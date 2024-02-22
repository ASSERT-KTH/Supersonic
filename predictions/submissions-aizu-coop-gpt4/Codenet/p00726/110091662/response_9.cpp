#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int N;
char dfs(const string& s, int& i) {
  vector<char> r;
  int n = 0;
  for (; i < s.size(); i++) {
    if ('0' <= s[i] && s[i] <= '9') {
      n = n * 10 + s[i] - '0';
    } else if (s[i] == '(') {
      int cnt = 1, j = i + 1;
      for (; cnt; j++) {
        if (s[j] == '(') cnt++;
        else if (s[j] == ')') cnt--;
      }
      vector<char> r0;
      int start = i + 1;
      for (int _ = 0; _ < n; _++) {
        i = start;
        while (r0.size() < N) {
          r0.push_back(dfs(s, i));
        }
        r.insert(r.end(), r0.begin(), r0.end());
        if (r.size() > N) return r[N];
      }
      n = 0;
      i = j;
    } else {
      r.insert(r.end(), n ? n : 1, s[i]);
      if (r.size() > N) return r[N];
      n = 0;
    }
  }
  return r.size() > N ? r[N] : '0';
}
int main() {
  for (;;) {
    string s;
    cin >> s >> N;
    if (s == "0") break;
    int start = 0;
    printf("%c\n", dfs(s, start));
  }
}