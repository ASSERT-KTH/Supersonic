#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

vector<vector<int>> involve;

vector<int> dfs2(int now, vector<bool>& used) {
  if (used[now]) return vector<int>{};
  used[now] = true;
  vector<int> ans;
  ans.reserve(involve[now].size());
  for (auto i : involve[now]) {
    if (!involve[i].empty()) {
      auto a = dfs2(i, used);
      ans.insert(ans.end(), a.begin(), a.end());
    } else {
      ans.emplace_back(i);
    }
  }
  return ans;
}

int main() {
  while (true) {
    int num = 0;
    unordered_map<string, int> mp;
    unordered_set<int> ed;
    int N;
    cin >> N;
    if (!N) break;
    involve.clear();
    involve.resize(100000);
    for (int i = 0; i < N; ++i) {
      string st;
      cin >> st;
      string groupname;
      vector<string> membername;
      int pre;
      for (int j = 0; j < st.size(); ++j) {
        if (st[j] == ':') {
          groupname = st.substr(0, j);
          pre = j;
        } else if (st[j] == ',' || st[j] == '.') {
          membername.push_back(st.substr(pre + 1, j - pre - 1));
          pre = j;
        }
      }
      if (!mp.count(groupname)) {
        mp[groupname] = num++;
      }
      for (auto& name : membername) {
        if (!mp.count(name)) {
          mp[name] = num++;
        }
      }
      for (auto& name : membername) {
        involve[mp[groupname]].emplace_back(mp[name]);
        ed.emplace(mp[name]);
      }
    }
    vector<bool> used(100001, false);
    auto allnames = dfs2(0, used);
    sort(allnames.begin(), allnames.end());
    const int ans = unique(allnames.begin(), allnames.end()) - allnames.begin();
    cout << ans << endl;
  }
  return 0;
}