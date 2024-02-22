#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
using namespace std;

string s;
priority_queue<string, vector<string>, greater<string>> pq;
int counter;

void dfs(int now) {
  if (now == s.size()) {
    counter++;
    pq.push(s);
    if (pq.size() > 10)
      pq.pop();
    return;
  }
  int d[26] = {};
  rep(i, 0, now) d[s[i] - 'a']++;
  char original_char = s[now];
  if (s[now] != 'z' && d[s[now] + 1 - 'a'] == 0) {
    s[now]++;
    dfs(now + 1);
    s[now] = original_char;  // restore the original character
  }
  if (s[now] == 'a' || d[s[now] - 'a'] != 0)
    dfs(now + 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (1) {
    cin >> s;
    if (s == "#")
      break;
    while (!pq.empty())
      pq.pop();
    counter = 0;
    dfs(0);
    cout << counter << endl;
    vector<string> vs;
    while (!pq.empty()) {
      vs.push_back(pq.top());
      pq.pop();
    }
    reverse(vs.begin(), vs.end());
    rep(i, 0, vs.size()) { cout << vs[i] << endl; }
  }
}