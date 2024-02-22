#include <algorithm>
#include <array>
#include <cassert>
#include <bitset>
#include <complex>
#include <cstdlib>
#include <deque>    // Added for optimization
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>     // Added for optimization
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>    // Added for optimization
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <unordered_map>    // Added for optimization
#include <unordered_set>    // Added for optimization
#include <vector>
using namespace std;

bool isPrime(long long int a) {
  if (a < 2)
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
  long long int aa = a;
  while (b > 0) {
    if (b & 1) {
      ans *= aa;
    }
    aa *= aa;
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
  else {
    used[now] = true;
  }
  vector<int> ans;
  stack<int> stk;    // Use stack for iterative depth-first search
  stk.push(now);
  while (!stk.empty()) {
    int curr = stk.top();
    stk.pop();
    for (auto i : involve[curr]) {
      if (involve[i].size()) {
        stk.push(i);
      } else {
        ans.push_back(i);
      }
    }
  }
  return ans;
}

int main() {
  while (1) {
    int num = 0;
    unordered_map<string, int> mp;    // Use unordered_map for faster lookup
    unordered_set<int> ed;            // Use unordered_set for faster lookup and insertion
    int N;
    cin >> N;
    if (!N)
      break;
    involve.clear();
    involve.resize(N);    // Resize the involve vector to the actual size of the input data
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
    vector<bool> used(num, false);    // Resize used vector to the actual number of elements
    vector<int> allnames(dfs2(0, used));
    sort(allnames.begin(), allnames.end());    // Consider using a more efficient sorting algorithm
    const int ans = unique(allnames.begin(), allnames.end()) - allnames.begin();
    cout << ans << endl;
  }
  return 0;
}