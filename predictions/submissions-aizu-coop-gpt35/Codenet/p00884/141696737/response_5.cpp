#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> involve;
vector<int> dfs2(const int now, vector<bool>& used, vector<int>& result) {
  if (used[now])
    return vector<int>();
  
  used[now] = true;
  
  for (auto i : involve[now]) {
    if (involve[i].size()) {
      dfs2(i, used, result);
    } else {
      result.push_back(i);
    }
  }
}

int main() {
  while (1) {
    int num = 0;
    map<string, int> mp;
    set<int> ed;
    int N;
    cin >> N;
    if (!N)
      break;
    involve.clear();
    involve.resize(N); // Resize based on the number of elements in the input
    
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
    
    vector<bool> used(num, false);
    vector<int> allnames;
    dfs2(0, used, allnames);
    
    const int ans = allnames.size();
    cout << ans << endl;
  }
  return 0;
}