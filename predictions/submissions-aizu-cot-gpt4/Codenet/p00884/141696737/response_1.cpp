#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

vector<unordered_set<int>> involve;

vector<int>* dfs2(const int now, vector<bool> &used) {
  if (used[now])
    return new vector<int>(0);
  else {
    used[now] = true;
  }
  vector<int>* ans = new vector<int>();
  for (auto i : involve[now]) {
    if (!involve[i].empty()) {
      vector<int>* a = dfs2(i, used);
      ans->insert(ans->end(), a->begin(), a->end());
      delete a;
    } else {
      ans->emplace_back(i);
    }
  }
  return ans;
}

int main() {
  while (1) {
    int num = 0;
    unordered_map<string, int> mp;
    int N;
    cin >> N;
    if (!N)
      break;
    involve.clear();
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
        involve[mp[groupname]].insert(mp[membername[i]]);
      }
    }
    involve.resize(num);
    vector<bool> used(num, false);
    vector<int>* allnames = dfs2(0, used);
    cout << allnames->size() << endl;
    delete allnames;
  }
  return 0;
}