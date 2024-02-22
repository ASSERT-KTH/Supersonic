#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> involve;

void dfs2(int now, vector<bool> &used, set<int> &ans) {
  if (used[now]) return;
  used[now] = true;
  
  for (auto i : involve[now]) {
    if (involve[i].size()) {
      dfs2(i, used, ans);
    } else {
      ans.insert(i);
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);

  while (1) {
    int num = 0;
    unordered_map<string, int> mp;
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
        if (!(mp.count(membername[i]))) {
          mp[membername[i]] = num++;
        }
      }
      for (int i = 0; i < membername.size(); ++i) {
        involve[mp[groupname]].push_back(mp[membername[i]]);
      }
    }
    vector<bool> used(100001, false);
    set<int> allnames;
    dfs2(0, used, allnames);
    cout << allnames.size() << endl;
  }
  return 0;
}