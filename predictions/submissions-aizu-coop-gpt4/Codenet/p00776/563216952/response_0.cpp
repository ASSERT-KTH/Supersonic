#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
using namespace std;

string s;
priority_queue<string, vector<string>, greater<string>> minHeap;
priority_queue<string> maxHeap;
int f[26];

inline void dfs(string& t, int now) {
  if (now == s.size()) {
    if (minHeap.size() < 5) {
      minHeap.push(t);
    } else if (t < minHeap.top()) {
      minHeap.pop();
      minHeap.push(t);
    }
    if (maxHeap.size() < 5) {
      maxHeap.push(t);
    } else if (t > maxHeap.top()) {
      maxHeap.pop();
      maxHeap.push(t);
    }
    return;
  }
  if (t[now] != 'z' && f[t[now] + 1 - 'a'] == 0) {
    t[now]++;
    f[t[now] - 'a']++;
    dfs(t, now + 1);
    f[t[now] - 'a']--;
    t[now]--;
  }
  if (t[now] == 'a' || f[t[now] - 1 - 'a'] != 0)
    dfs(t, now + 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (1) {
    cin >> s;
    if (s == "#")
      break;
    while (!minHeap.empty()) minHeap.pop();
    while (!maxHeap.empty()) maxHeap.pop();
    memset(f, 0, sizeof(f));
    dfs(s, 0);
    cout << minHeap.size() + maxHeap.size() << endl;
    vector<string> ans;
    while (!minHeap.empty()) {
      ans.push_back(minHeap.top());
      minHeap.pop();
    }
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << endl;
    }
    ans.clear();
    while (!maxHeap.empty()) {
      ans.push_back(maxHeap.top());
      maxHeap.pop();
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
      cout << ans[i] << endl;
    }
  }
  return 0;
}