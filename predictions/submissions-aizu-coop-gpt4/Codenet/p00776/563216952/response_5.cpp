#include <bits/stdc++.h>
using namespace std;

string s;
set<string> st;
bool f[26];

// the function now receives d as a parameter and t is passed by reference
void dfs(string &t, int now, int d[26]) {
  if (now == s.size()) {
    st.insert(t);
    return;
  }
  
  if (t[now] != 'z' && d[t[now] + 1 - 'a'] == 0) {
    // incrementing the ASCII value of the letter in the string
    t[now]++;
    dfs(t, now + 1, d);
    t[now]--; // undo the change for the next recursion
  }
  if (t[now] == 'a' || d[t[now] - 'a'] != 0)
    dfs(t, now + 1, d);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> s, s != "#") {
    st.clear();
    int d[26] = {};
    for (int i = 0; i < s.size(); i++) d[s[i] - 'a']++;
    dfs(s, 0, d);
    
    int ans = st.size();
    cout << ans << endl;

    auto it = st.begin();
    if (ans <= 10) {
      for (const auto &str : st) {
        cout << str << endl;
      }
    } else {
      for (int i = 0; i < 5; i++, it++) {
        cout << *it << endl;
      }
      for (it = prev(st.end(), 5); it != st.end(); it++) {
        cout << *it << endl;
      }
    }
  }

  return 0;
}