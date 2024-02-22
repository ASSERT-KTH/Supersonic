#include <algorithm>
#include <array>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> involve;

void dfs2(const int now, vector<bool> &used, unordered_set<int>& ans) {
  if (used[now])
    return;
  else {
    used[now] = true;
  }
  for (auto i : involve[now]) {
    if (involve[i].size()) {
      dfs2(i, used, ans);
    } else {
      ans.insert(i);
    }
  }
}

int main() {
  while (1) {
    int num = 0;
    unordered_map<string, int> mp;
    unordered_set<int> ed;
    int N;
    cin >> N;
    if (!N)
      break;
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
        if (!(mp.count(membername[i]))) {
          mp[membername[i]] = num++;
        }
      }
      for (int i = 0; i < membername.size(); ++i) {
        involve[mp[groupname]].push_back(mp[membername[i]]);
        ed.emplace(mp[membername[i]]);
      }
    }
    vector<bool> used(100001, false);
    unordered_set<int> allnames;
    dfs2(0, used, allnames);
    cout << allnames.size() << endl;
  }
  return 0;
}