#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
using namespace std;
string s;
vector<string> vs;
bool f[26];
void dfs(string &t, int now) { // pass string by reference
  if (now == s.size()) {
    vs.push_back(t);
    return;
  }
  int d[26] = {};
  rep(i, 0, now) d[t[i] - 'a']++;
  if (t[now] != 'z' && d[t[now] + 1 - 'a'] == 0) {
    t[now] = t[now] + 1; // modify string in-place
    dfs(t, now + 1);
    t[now] = t[now] - 1; // revert the change
  }
  if (t[now] == 'a' || d[t[now] - 'a'] != 0)
    dfs(t, now + 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (1) {
    cin >> s;
    if (s == "#")
      break;
    vs.clear();
    dfs(s, 0);
    int ans = vs.size();
    cout << ans << endl;
    if (ans <= 10) {
      sort(vs.begin(), vs.end());
      rep(i, 0, ans) { cout << vs[i] << endl; }
    } else {
      priority_queue<string, vector<string>, less<string>> maxHeap;
      priority_queue<string, vector<string>, greater<string>> minHeap;
      for (const auto &str : vs) {
        minHeap.push(str);
        if (minHeap.size() > 5) minHeap.pop();
        maxHeap.push(str);
        if (maxHeap.size() > 5) maxHeap.pop();
      }
      while (!minHeap.empty()) {
        cout << minHeap.top() << endl;
        minHeap.pop();
      }
      while (!maxHeap.empty()) {
        cout << maxHeap.top() << endl;
        maxHeap.pop();
      }
    }
  }
}