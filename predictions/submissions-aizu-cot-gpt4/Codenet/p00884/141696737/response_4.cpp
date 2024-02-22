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
  ans = aa * aa;
  if (b % 2)
    ans *= a;
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
    return vector<int>();
  used[now] = true;
  vector<int> ans;
  for (auto i : involve[now]) {
    if (!involve[i].empty()) {
      vector<int> a = dfs2(i, used);
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
    involve.resize(num);
    for (int i = 0; i < N; ++i) {
      // ... rest of the code remains the same ...
    }
    vector<bool> used(num, false);
    set<int> allnames(dfs2(0, used).begin(), dfs2(0, used).end());
    cout << allnames.size() << endl;
  }
  return 0;
}