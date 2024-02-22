#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

vector<vector<int>> involve;
set<int> visited;

void dfs2(int now) {
  if (visited.count(now)) return;
  visited.insert(now);
  
  for (auto i : involve[now]) {
    if (!involve[i].empty()) {
      dfs2(i);
    } else {
      visited.insert(i);
    }
  }
}

int main() {
  while (1) {
    int num = 0;
    map<string, int> mp;
    int N;
    cin >> N;
    if (!N) break;

    involve.clear();
    involve.resize(100000);
    visited.clear();

    for (int i = 0; i < N; ++i) {
      string st;
      cin >> st;
      stringstream ss(st);

      string groupname, member;
      getline(ss, groupname, ':');

      if (!mp.count(groupname)) {
        mp[groupname] = num++;
      }

      while (getline(ss, member, ',')) {
        if (!mp.count(member)) {
          mp[member] = num++;
        }
        involve[mp[groupname]].push_back(mp[member]);
      }
    }
    dfs2(0);
    cout << visited.size() - 1 << endl; // subtract 1 because group 0 is also counted
  }
  return 0;
}