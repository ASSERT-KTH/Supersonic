#include <bits/stdc++.h>
using namespace std;
int N, M;
int A[3];
vector<int> G[51];
bool used[51];
unordered_map<pair<int,int>, unordered_set<int>, pair_hash> paths;
unordered_map<int, unordered_set<int>> reachable[3];
int main() {
  cin >> N >> M;
  for (int i = 0; i < 3; i++)
    cin >> A[i];
  for (int i = 0; i < M; i++) {
    int f, t;
    cin >> f >> t;
    f--;
    t--;
    G[f].push_back(t);
  }
  for (int i = 0; i < N; i++)
    paths[{i, i}].insert(0);
  for (int i = 1; i < 101; i++) {
    for (int j = 0; j < N; j++) {
      for (int to : G[j]) {
        if (paths[{j, to}].count(i - 1)) {
          paths[{j, to}].insert(i);
          if (i == A[0] || i == A[1] || i == A[2])
            reachable[i][j].insert(to);
        }
      }
    }
  }
  used[N - 1] = true;
  for (int ite = 1;; ite++) {
    bool ok = false;
    vector<int> idx;
    for (int i = 0; i < N; i++) {
      if (used[i])
        continue;
      int cnt = 0;
      for (int j = 0; j < 3; j++) {
        for (int to : reachable[A[j]][i]) {
          if (used[to]) {
            cnt++;
            break;
          }
        }
      }
      if (cnt == 3) {
        ok = true;
        idx.push_back(i);
      }
    }
    if (ok) {
      for (int i : idx) {
        used[i] = true;
      }
      if (used[0]) {
        cout << ite << endl;
        return 0;
      }
    } else {
      break;
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}