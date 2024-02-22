#include <algorithm>
#include <array>
#include <assert.h>
#include <bitset>
#include <complex>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

bool isso(long long int a) {
  if (a == 2)
    return true;
  if (a < 2 || a % 2 == 0)
    return false;
  for (long long int i = 3; i * i <= a; i += 2) {
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
  long long int ans = 1;
  while (b) {
    if (b & 1)
      ans *= a;
    a *= a;
    b >>= 1;
  }
  return ans;
}

struct edge {
  int from;
  int to;
  int cost;
};

struct aa {
  int now;
  int fuel;
  int cost;
};

class Compare {
public:
  bool operator()(const aa &l, const aa &r) { return l.cost > r.cost; }
};

vector<vector<int>> involve;

vector<int> dfs2(const int now, vector<bool> &used) {
  if (used[now])
    return vector<int>(0);
  used[now] = true;
  vector<int> ans;
  for (auto i : involve[now]) {
    if (!involve[i].empty()) {
      vector<int> a(dfs2(i, used));
      ans.reserve(ans.size() + a.size());
      ans.insert(ans.end(), a.begin(), a.end());
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
      int groupIndex = mp[groupname];
      if (groupIndex >= involve.size()) {
        involve.resize(groupIndex + 1);
      }
      for (int i = 0; i < membername.size(); ++i) {
        if (!mp.count(membername[i])) {
          mp[membername[i]] = num++;
        }
        int memberIndex = mp[membername[i]];
        involve[groupIndex].push_back(memberIndex);
        ed.emplace(memberIndex);
      }
    }
    vector<bool> used(num, false);
    vector<int> allnames(dfs2(0, used));
    set<int> uniqueNames(allnames.begin(), allnames.end());
    cout << uniqueNames.size() << endl;
  }
  return 0;
}