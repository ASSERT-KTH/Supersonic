#include <algorithm>
#include <array>
#include <assert.h>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> involve;

vector<int> dfs2(const int now, vector<bool> &used) {
  if (used[now]) return vector<int>(0);
  
  used[now] = true;
  vector<int> ans;
  ans.reserve(involve[now].size());

  for (auto i : involve[now]) {
    if (involve[i].size()) {
      vector<int> a(dfs2(i, used));
      ans.insert(ans.end(), make_move_iterator(a.begin()), make_move_iterator(a.end()));
    } else {
      ans.push_back(i);
    }
  }
  return ans;
}

int main() {
  while (1) {
    int num = 0;
    map<string, int> mp;
    set<int> ed;
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
      for (int i = 0; i < membername.size(); ++i) {
        auto it = mp.find(membername[i]);
        if (it == mp.end()) {
          mp[membername[i]] = num++;
        }
      }
      for (int i = 0; i < membername.size(); ++i) {
        involve[mp[groupname]].push_back(mp[membername[i]]);
        ed.emplace(mp[membername[i]]);
      }
    }
    vector<bool> used(100001, false);
    vector<int> allnames(dfs2(0, used));
    sort(allnames.begin(), allnames.end());
    const int ans(unique(allnames.begin(), allnames.end()) - allnames.begin());
    cout << ans << endl;
  }
  return 0;
}