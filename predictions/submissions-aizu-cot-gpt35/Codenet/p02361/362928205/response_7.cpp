#include <algorithm>
#include <iostream>
#include <list>
#include <deque>
#include <vector>

using namespace std;

const int INF = 1000000000;

struct edge {
  int to, cost;
};

list<edge> G[100000];
int v, e, r;

struct Compare {
  bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) {
    return lhs.first > rhs.first;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> v >> e >> r;

  for (int i = 0; i < e; i++) {
    int s, t, d;
    cin >> s >> t >> d;
    edge tmp;
    tmp.to = t;
    tmp.cost = d;
    G[s].push_back(tmp);
  }

  int d[v];
  for (int i = 0; i < v; i++) {
    d[i] = INF;
  }
  d[r] = 0;

  deque<pair<int, int>> q;
  q.push_front({0, r});

  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop_front();

    int nv = p.second;
    if (p.first > d[nv])
      continue;

    for (auto it = G[nv].begin(); it != G[nv].end(); ++it) {
      if (d[nv] + it->cost < d[it->to]) {
        d[it->to] = d[nv] + it->cost;

        if (d[it->to] < p.first) {
          q.push_front({d[it->to], it->to});
        } else {
          q.push_back({d[it->to], it->to});
        }
      }
    }
  }

  for (int i = 0; i < v; i++) {
    if (d[i] == INF)
      cout << "INF\n";
    else
      cout << d[i] << "\n";
  }

  return 0;
}