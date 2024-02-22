#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define rep(i, a, n) for (int i = a; i < n; i++)
using namespace std;

void dfs(string &s, int now, int &ans, vector<string> &smallest, vector<string> &largest, int d[]) {
  if (now == s.size()) {
    ans++;
    if (smallest.size() < 5) {
      smallest.push_back(s);
      if (smallest.size() == 5)
        make_heap(smallest.begin(), smallest.end());
    } else if (s < smallest.front()) {
      pop_heap(smallest.begin(), smallest.end());
      smallest.pop_back();
      smallest.push_back(s);
      push_heap(smallest.begin(), smallest.end());
    }
    if (largest.size() < 5) {
      largest.push_back(s);
      if (largest.size() == 5)
        make_heap(largest.begin(), largest.end(), greater<string>());
    } else if (s > largest.front()) {
      pop_heap(largest.begin(), largest.end(), greater<string>());
      largest.pop_back();
      largest.push_back(s);
      push_heap(largest.begin(), largest.end(), greater<string>());
    }
    return;
  }
  if (s[now] != 'z' && d[s[now] + 1 - 'a'] == 0) {
    s[now]++;
    d[s[now] - 'a']++;
    dfs(s, now + 1, ans, smallest, largest, d);
    d[s[now] - 'a']--;
    s[now]--;
  }
  if (s[now] == 'a' || d[s[now] - 1 - 'a'] != 0)
    dfs(s, now + 1, ans, smallest, largest, d);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  while (1) {
    cin >> s;
    if (s == "#")
      break;
    int ans = 0;
    int d[26] = {};
    vector<string> smallest, largest;
    dfs(s, 0, ans, smallest, largest, d);
    cout << ans << endl;
    sort(smallest.begin(), smallest.end());
    for (string &str : smallest) {
      cout << str << endl;
    }
    if (ans > 10) {
      sort(largest.begin(), largest.end());
      for (string &str : largest) {
        cout << str << '\n';
      }
    }
  }
  return 0;
}