#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
using namespace std;
string s;
priority_queue<string, vector<string>, greater<string>> smallest;
priority_queue<string> largest;
int d[26] = {};

void dfs(string &t, int now) {
  if (now == s.size()) {
    if (smallest.size() < 5) {
      smallest.push(t);
      largest.push(t);
    } else {
      if (t < smallest.top()) {
        smallest.pop();
        smallest.push(t);
      }
      if (t > largest.top()) {
        largest.pop();
        largest.push(t);
      }
    }
    return;
  }
  d[t[now] - 'a']++;
  if (t[now] != 'z' && d[t[now] + 1 - 'a'] == 0) {
    t[now] = t[now] + 1;
    dfs(t, now + 1);
    t[now] = t[now] - 1;
  }
  if (t[now] == 'a' || d[t[now] - 'a'] != 0)
    dfs(t, now + 1);
  d[t[now] - 'a']--;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (1) {
    cin >> s;
    if (s == "#")
      break;
    while (!smallest.empty()) smallest.pop();
    while (!largest.empty()) largest.pop();
    dfs(s, 0);
    int ans = smallest.size() + largest.size();
    cout << ans << endl;
    while (!smallest.empty()) {
      cout << smallest.top() << endl;
      smallest.pop();
    }
    while (!largest.empty()) {
      cout << largest.top() << endl;
      largest.pop();
    }
  }
}