#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
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

long long int powInt(long long int a, long long int b) {
  assert(b >= 0);
  if (b == 0)
    return 1;
  if (b == 1)
    return a;
  long long int ans = 1;
  long long int aa = powInt(a, b / 2);
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
    unordered_map<string, int> mp;
    int N;
    cin >> N;
    if (!N)
      break;
    involve.clear();
    involve.resize(N);
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
      }
    }
    vector<bool> used(num, false);
    vector<int> allnames(dfs2(0, used));
    sort(allnames.begin(), allnames.end());
    allnames.erase(unique(allnames.begin(), allnames.end()), allnames.end());
    const int ans = allnames.size();
    cout << ans << endl;
  }
  return 0;
}