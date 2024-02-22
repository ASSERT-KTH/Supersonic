#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool is_prime(long long int a) {
  if (a < 2)
    return false;
  if (a < 4)
    return true;
  if (a % 2 == 0 || a % 3 == 0)
    return false;
  for (long long int i = 5; i * i <= a; i += 6) {
    if (a % i == 0 || a % (i + 2) == 0)
      return false;
  }
  return true;
}

long long int powint(long long int a, long long int b) {
  assert(b >= 0);
  if (b == 0)
    return 1;
  long long int ans = 1;
  while (b > 0) {
    if (b & 1)
      ans *= a;
    a *= a;
    b >>= 1;
  }
  return ans;
}

vector<int> dfs2(const int now, vector<int> &visited, const vector<vector<int>>& involve) {
  if (visited[now] != -1)
    return vector<int>(0);
  visited[now] = 0;
  vector<int> ans;
  for (auto i : involve[now]) {
    if (visited[i] != 0) {
      vector<int> a(dfs2(i, visited, involve));
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
    unordered_set<int> ed;
    int N;
    cin >> N;
    if (!N)
      break;
    vector<vector<int>> involve(N);
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
    vector<int> visited(num, -1);
    vector<int> allnames(dfs2(0, visited, involve));
    sort(allnames.begin(), allnames.end());
    const int ans(unique(allnames.begin(), allnames.end()) - allnames.begin());
    cout << ans << endl;
  }
  return 0;
}