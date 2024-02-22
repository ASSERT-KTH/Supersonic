#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
using namespace std;
string s;
priority_queue<string> minHeap;
priority_queue<string, vector<string>, greater<string>> maxHeap;
void dfs(string &t, int now, int &cnt) {
  if (now == s.size()) {
    cnt++;
    if(minHeap.size() < 5) {
      minHeap.push(t);
    } else if(t < minHeap.top()) {
      minHeap.pop();
      minHeap.push(t);
    }
    if(maxHeap.size() < 5) {
      maxHeap.push(t);
    } else if(t > maxHeap.top()) {
      maxHeap.pop();
      maxHeap.push(t);
    }
    return;
  }
  int d[26] = {};
  rep(i, 0, now) d[t[i] - 'a']++;
  if (t[now] != 'z' && d[t[now] + 1 - 'a'] == 0) {
    t[now] = t[now] + 1;
    dfs(t, now + 1, cnt);
    t[now] = t[now] - 1;
  }
  if (t[now] == 'a' || d[t[now] - 'a'] != 0)
    dfs(t, now + 1, cnt);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (1) {
    cin >> s;
    if (s == "#")
      break;
    int cnt = 0;
    dfs(s, 0, cnt);
    cout << cnt << endl;
    vector<string> minStrings, maxStrings;
    while(!minHeap.empty()) {
      minStrings.push_back(minHeap.top());
      minHeap.pop();
    }
    while(!maxHeap.empty()) {
      maxStrings.push_back(maxHeap.top());
      maxHeap.pop();
    }
    for(int i = minStrings.size() - 1; i >= 0; i--)
      cout << minStrings[i] << "\n";
    for(string str : maxStrings)
      cout << str << "\n";
  }
}