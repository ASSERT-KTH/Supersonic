#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <assert.h>
using namespace std;

bool isso(long long int a) {
  if (a == 1 || a == 0)
    return false;
  for (long long int i = 2; i * i <= a; ++i) {
    if (!(a % i)) {
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

void dfs2(int now, vector<int>& ans, vector<bool>& used) {
  if (used[now])
    return;
  else {
    used[now] = true;
  }
  for (auto i : involve[now]) {
    if (involve[i].size()) {
      dfs2(i, ans, used);
    } else {
      ans.push_back(i);
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
    involve.resize(100000);
    for (int i = 0; i < N; ++i) {
      string st;
      cin >> st;
      stringstream ss(st);
      string groupname;
      getline(ss, groupname, ':');
      if (!mp.count(groupname)) {
        mp[groupname] = num++;
      }
      string membername;
      while (getline(ss, membername, ',')) {
        if (!(mp.count(membername))) {
          mp[membername] = num++;
        }
        involve[mp[groupname]].push_back(mp[membername]);
        ed.emplace(mp[membername]);
      }
    }
    vector<bool> used(100001, false);
    vector<int> allnames;
    allnames.reserve(100000);
    dfs2(0, allnames, used);
    sort(allnames.begin(), allnames.end());
    const int ans(unique(allnames.begin(), allnames.end()) - allnames.begin());
    cout << ans << endl;
  }
  return 0;
}