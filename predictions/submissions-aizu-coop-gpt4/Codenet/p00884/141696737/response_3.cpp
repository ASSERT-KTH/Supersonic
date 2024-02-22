#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> involve;
unordered_map<string, int> mp;
unordered_set<int> ed;

void dfs2(int now, vector<bool> &used, vector<int> &ans) {
  if (used[now])
    return;
  used[now] = true;

  for (auto i : involve) {
    if (involve.size()) {
      dfs2(i, used, ans);
    } else {
      ans.push_back(i);
    }
  }
}

int main() {
  while (1) {
    int num = 0;
    int N;
    cin >> N;
    if (!N)
      break;
    involve.clear();
    mp.clear();
    ed.clear();
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
        if (!(mp.count(membername[i]))) {
          mp[membername[i]] = num++;
        }
      }
      for (int i = 0; i < membername.size(); ++i) {
        involve.push_back(mp[membername[i]]);
        ed.emplace(mp[membername[i]]);
      }
    }
    vector<bool> used(100001, false);
    vector<int> allnames;
    dfs2(0, used, allnames);
    sort(allnames.begin(), allnames.end());
    const int ans(unique(allnames.begin(), allnames.end()) - allnames.begin());
    cout << ans << endl;
  }
  return 0;
}