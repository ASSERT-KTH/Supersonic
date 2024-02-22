#include <iostream>
#include <queue>
using namespace std;

int n;
bool** m;
bool* v;
int* d;

void bfs(int s) {
  v[s] = true;
  d[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < n; i++) {
      if (!v[i]) {
        d[i] = d[u] + 1;
        v[i] = true;
        q.push(i);
      }
    }
  }
}

int main() {
  cin >> n;
  m = new bool*[n];
  v = new bool[n];
  d = new int[n];
  for (int i = 0; i < n; i++) {
    m[i] = new bool[n];
    v[i] = false;
    d[i] = -1;
    for (int j = 0; j < n; j++) {
      m[i][j] = false;
    }
  }
  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      int v;
      cin >> v;
      m[u - 1][v - 1] = true;
    }
  }
  bfs(0);
  for (int i = 0; i < n; i++) {
    cout << i + 1 << ' ' << d[i] << endl;
  }
  for (int i = 0; i < n; i++) {
    delete[] m[i];
  }
  delete[] m;
  delete[] v;
  delete[] d;
  return 0;
}