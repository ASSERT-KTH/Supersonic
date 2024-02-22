#include <iostream>
#include <vector>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

vector<vector<int>> adjList;
vector<int> color;
vector<int> d, f;
int t;

void search_loop(int i) {
  d[i] = ++t;
  color[i] = GRAY;

  for (int next : adjList[i]) {
    if (color[next] == WHITE) {
      search_loop(next);
    }
  }

  f[i] = ++t;
  color[i] = BLACK;
}

void dfs() {
  for (int i = 1; i < adjList.size(); i++) {
    color[i] = WHITE;
  }

  t = 0;

  for (int i = 1; i < adjList.size(); i++) {
    if (color[i] == WHITE) {
      search_loop(i);
    }
  }

  for (int i = 1; i < adjList.size(); i++) {
    cout << i << " " << d[i] << " " << f[i] << endl;
  }
}

int main() {
  int n;
  cin >> n;

  adjList.resize(n + 1);
  color.resize(n + 1);
  d.resize(n + 1);
  f.resize(n + 1);

  for (int i = 1; i <= n; i++) {
    int e;
    cin >> e;

    for (int j = 1; j <= e; j++) {
      int k;
      cin >> k;
      adjList[i].push_back(k);
    }
  }

  dfs();
  
  return 0;
}