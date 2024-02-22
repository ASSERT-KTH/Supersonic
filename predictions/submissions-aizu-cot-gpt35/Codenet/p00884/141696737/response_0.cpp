#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

bool isso(long long int a) {
  if (a == 1 || a == 0)
    return false;
  for (long long int i = 2; i * i <= a; ++i) {
    if ((a % i)) {
    } else {
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

std::vector<std::vector<int>> involve;

void dfs2(const int now, std::vector<bool> &used, std::set<int> &allnames) {
  if (used[now])
    return;
  else {
    used[now] = true;
  }
  for (auto i : involve[now]) {
    if (involve[i].size()) {
      dfs2(i, used, allnames);
    } else {
      allnames.insert(i);
    }
  }
}

int main() {
  while (1) {
    int num = 0;
    std::map<std::string, int> mp;
    std::set<int> ed;
    int N;
    std::cin >> N;
    if (!N)
      break;
    involve.clear();
    involve.resize(100000);
    for (int i = 0; i < N; ++i) {
      std::string st;
      std::cin >> st;
      std::string groupname;
      std::vector<std::string> membername;
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
    std::vector<bool> used(100001, false);
    std::set<int> allnames;
    dfs2(0, used, allnames);
    const int ans = allnames.size();
    std::cout << ans << std::endl;
  }
  return 0;
}