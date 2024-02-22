#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

bool isso(long long int a) {
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
  if (b == 0)
    return 1;
  if (b == 1)
    return a;
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

vector<vector<int>> involve;

void dfs2(const int now, vector<bool> &used, vector<int> &ans) {
  if (used[now])
    return;
  used[now] = true;

  for (auto i : involve[now]) {
    if (involve[i].size()) {
      dfs2(i, used, ans);
    } else {
      ans.push_back(i);
    }
  }
}

int main() {
  while (1) {
    int num = 0;
    vector<string> names;
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

      int groupId = -1;
      for (int i = 0; i < names.size(); ++i) {
        if (names[i] == groupname) {
          groupId = i;
          break;
        }
      }
      if (groupId == -1) {
        groupId = num++;
        names.push_back(groupname);
      }

      for (int i = 0; i < membername.size(); ++i) {
        int memberId = -1;
        for (int i = 0; i < names.size(); ++i) {
          if (names[i] == membername[i]) {
            memberId = i;
            break;
          }
        }
        if (memberId == -1) {
          memberId = num++;
          names.push_back(membername[i]);
        }
        involve[groupId].push_back(memberId);
      }
    }

    vector<bool> used(num, false);
    vector<int> allnames;
    dfs2(0, used, allnames);

    set<int> uniqueNames(allnames.begin(), allnames.end());

    cout << uniqueNames.size() << endl;
  }

  return 0;
}