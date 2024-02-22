#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
using namespace std;

string s;
priority_queue<string, vector<string>, greater<string>> pq;
priority_queue<string, vector<string>, less<string>> pq1;
bool f[26];

void dfs(string t, int now, int d[]) {
  if (now == s.size()) {
    if (pq.size() < 5) {
      pq.push(t);
      pq1.push(t);
    } else if (pq.top() < t) {
      pq.pop();
      pq.push(t);
    } else if (pq1.top() > t) {
      pq1.pop();
      pq1.push(t);
    }
    return;
  }
  if (t[now] != 'z' && d[t[now] + 1 - 'a'] == 0) {
    string tmp = t;
    tmp[now] = tmp[now] + 1;
    d[t[now] - 'a']--;
    d[tmp[now] - 'a']++;
    dfs(tmp, now + 1, d);
    d[tmp[now] - 'a']--;
    d[t[now] - 'a']++;
  }
  if (t[now] == 'a' || d[t[now] - 1 - 'a'] != 0)
    dfs(t, now + 1, d);
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
    while (!pq1.empty())
      pq1.pop();
    int d[26] = {};
    dfs(s, 0, d);
    int ans = pq.size() + pq1.size();
    cout << ans << endl;
    while (!pq1.empty()) {
      cout << pq1.top() << endl;
      pq1.pop();
    }
    while (!pq.empty()) {
      cout << pq.top() << endl;
      pq.pop();
    }
  }
}