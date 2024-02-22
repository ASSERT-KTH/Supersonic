#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

bool isPrime(long long int a) {
  if (a < 2)
    return false;
  if (a == 2)
    return true;
  if (a % 2 == 0)
    return false;
  for (long long int i = 3; i * i <= a; i += 2) {
    if (a % i == 0) {
      return false;
    }
  }
  return true;
}

long long int powint(long long int a, long long int b) {
  if (b == 0)
    return 1;
  long long int ans = powint(a, b / 2);
  ans *= ans;
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

vector<set<int>> involve;

vector<int> dfs2(const int now, vector<bool> &used) {
  vector<int> ans;
  stack<int> stk;
  stk.push(now);
  
  while (!stk.empty()) {
    int curr = stk.top();
    stk.pop();
    
    if (used[curr])
      continue;

    used[curr] = true;
    
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
    map<string, int> mp;
    set<int> ed;
    int N;
    cin >> N;
    if (!N)
      break;
    involve.clear();
    involve.reserve(100000);
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
        ed.emplace(mp[membername[i]]);
      }
    }
    vector<bool> used(100001, false);
    vector<int> allnames(dfs2(0, used));
    const int ans = allnames.size();
    cout << ans << endl;
  }
  return 0;
}