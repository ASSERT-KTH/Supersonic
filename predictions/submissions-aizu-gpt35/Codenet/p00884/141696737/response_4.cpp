#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
#include <string>
#include <vector>
using namespace std;

bool is_prime(long long int a) {
  if (a < 2) {
    return false;
  }
  for (long long int i = 2; i * i <= a; ++i) {
    if (a % i == 0) {
      return false;
    }
  }
  return true;
}

long long int powint(long long int a, long long int b) {
  assert(b >= 0);
  if (b == 0) {
    return 1;
  }
  if (b == 1) {
    return a;
  }
  long long int ans = 1;
  long long int aa = powint(a, b / 2);
  ans *= aa * aa;
  if (b % 2) {
    ans *= a;
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
  if (used[now]) {
    return vector<int>(0);
  } else {
    used[now] = true;
  }
  vector<int> ans;
  for (auto i : involve[now]) {
    if (involve[i].size()) {
      vector<int> a(dfs2(i, used));
      ans.insert(ans.end(), a.begin(), a.end());
    } else {
      ans.push_back(i);
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  while (true) {
    int num = 0;
    map<string, int> mp;
    set<int> ed;
    int N;
    cin >> N;
    if (!N) {
      break;
    }
    involve.clear();
    involve.resize(100000);
    for (int i = 0; i < N; ++i) {
      string st;
      cin >> st;
      string groupname;
      vector<string> membername;
      int pre = -1;
      int idx = 0;
      while (idx < st.size()) {
        if (st[idx] == ':') {
          groupname = st.substr(0, idx);
          pre = idx;
        } else if (st[idx] == ',' || st[idx] == '.') {
          membername.push_back(st.substr(pre + 1, idx - pre - 1));
          pre = idx;
        }
        ++idx;
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
    vector<int> allnames(dfs2(0, used));
    sort(allnames.begin(), allnames.end());
    const int ans(unique(allnames.begin(), allnames.end()) - allnames.begin());
    cout << ans << endl;
  }
  return 0;
}