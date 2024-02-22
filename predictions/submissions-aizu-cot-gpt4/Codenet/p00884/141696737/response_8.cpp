#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

bool isso(long long int a) {
  if (a == 1 || a == 0)
    return false;
  for (long long int i = 2; i * i <= a; ++i) {
    if (a % i == 0) {
      return false;
    }
  }
  return true;
}

long long int powint(long long int a, long long int b) {
  assert(b >= 0);
  if (b == 0)
    return 1;
  if (b == 1)
    return a;
  long long int ans = 1;
  long long int aa = powint(a, b / 2);
  ans *= aa * aa;
  if (b % 2)
    ans *= a;
  return ans;
}

vector<vector<int>> involve;

vector<int> dfs2(const int now, vector<bool> &used) {
  if (used[now])
    return vector<int>(0);
  else {
    used[now] = true;
  }
  vector<int> ans;
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
      int group_index;
      if (!mp.count(groupname)) {
        group_index = num++;
        mp[groupname] = group_index;
      } else {
        group_index = mp[groupname];
      }
      vector<int> member_indices(membername.size());
      for (int i = 0; i < membername.size(); ++i) {
        if (!mp.count(membername[i])) {
          member_indices[i] = num++;
          mp[membername[i]] = member_indices[i];
        } else {
          member_indices[i] = mp[membername[i]];
        }
      }
      for (int i = 0; i < membername.size(); ++i) {
        involve[group_index].push_back(member_indices[i]);
        ed.emplace(member_indices[i]);
      }
    }
    vector<bool> used(100001, false);
    vector<int> allnames(dfs2(0, used));
    sort(allnames.begin(), allnames.end());
    const int ans(unique(allnames.begin(), allnames.end()) - allnames.begin());
    cout << ans << '\n';
  }
  return 0;
}