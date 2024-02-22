#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, q;
  cin >> n >> m >> q;

  vector<vector<pair<int, int>>> x(n + 1);
  vector<int> dist(n + 1, 999999);
  vector<int> T(n + 1);
  vector<bool> U(n + 1);
  vector<bool> used(m);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    x[a].push_back(make_pair(b, i));
    x[b].push_back(make_pair(a, i));
  }

  dist[1] = 0;
  deque<int> Q;
  Q.push_back(1);

  while (!Q.empty()) {
    int a1 = Q.front();
    Q.pop_front();

    for (pair<int, int> i : x[a1]) {
      if (dist[i.first] > dist[a1] + 1) {
        dist[i.first] = dist[a1] + 1;
        Q.push_back(i.first);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (pair<int, int> j : x[i]) {
      if (dist[i] < dist[j.first]) {
        T[j.first]++;
      }
    }
  }

  int cnt = 0;

  for (int i = 0; i < q; i++) {
    int c;
    cin >> c;
    c--;

    deque<pair<int, int>> Q1;
    int ss = -1;

    if (dist[x[c][0].first] < dist[x[c][1].first]) {
      ss = x[c][1].first;
    } else if (dist[x[c][0].first] > dist[x[c][1].first]) {
      ss = x[c][0].first;
    }

    if (ss >= 1 && U[ss] == 0 && used[c] == false) {
      Q1.push_back(make_pair(ss, c));

      while (!Q1.empty()) {
        int a1 = Q1.front().first;
        int a2 = Q1.front().second;
        Q1.pop_front();

        if (U[a1] == 1 || used[a2] == true) {
          continue;
        }

        T[a1]--;
        used[a2] = true;

        if (T[a1] != 0) {
          continue;
        }

        cnt++;
        U[a1] = 1;

        for (pair<int, int> j : x[a1]) {
          if (U[j.first] == 0) {
            Q1.push_back(j);
          }
        }
      }
    }

    cout << cnt << endl;
  }

  return 0;
}