#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
using namespace std;
string s;
priority_queue<string, vector<string>, greater<string>> minHeap;
priority_queue<string> maxHeap;
bool f[26];

void dfs(string& t, int now) {
  if (now == s.size()) {
    minHeap.push(t);
    if (minHeap.size() > 5) {
      minHeap.pop();
    }
    maxHeap.push(t);
    if (maxHeap.size() > 5) {
      maxHeap.pop();
    }
    return;
  }
  int d[26] = {};
  rep(i, 0, now) d[t[i] - 'a']++;
  if (t[now] != 'z' && d[t[now] + 1 - 'a'] == 0) {
    t[now] = t[now] + 1;
    dfs(t, now + 1);
    t[now] = t[now] - 1;  // undo the change
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
    while (!minHeap.empty()) {
      minHeap.pop();
    }
    while (!maxHeap.empty()) {
      maxHeap.pop();
    }
    dfs(s, 0);
    int ans = minHeap.size() + maxHeap.size();
    cout << ans << endl;
    stack<string> stk;
    while (!minHeap.empty()) {
      stk.push(minHeap.top());
      minHeap.pop();
    }
    while (!stk.empty()) {
      cout << stk.top() << endl;
      stk.pop();
    }
    vector<string> temp;
    while (!maxHeap.empty()) {
      temp.push_back(maxHeap.top());
      maxHeap.pop();
    }
    for (int i = temp.size() - 1; i >= 0; i--) {
      cout << temp[i] << endl;
    }
  }
}