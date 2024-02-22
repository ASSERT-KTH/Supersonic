#include <iostream>
#include <queue>
using namespace std;

void bfs(int s, bool* v, int* d, bool** m, int n) {
  v[s] = true;
  d[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < n; i++) {
      if (m[u][i] && !v[i]) {
        d[i] = d[u] + 1;
        v[i] = true;
        q.push(i);
      }
    }
  }
}

int main() {
  int n;
  cin >> n;

  bool** m = new bool*[n];
  for (int i = 0; i < n; i++) {
    m[i] = new bool[n];
    for (int j = 0; j < n; j++) {
      m[i][j] = false; // Initialize all elements to false
    }
  }

  int* d = new int[n];
  bool* v = new bool[n];
  for (int i = 0; i < n; i++) {
    d[i] = -1;
    v[i] = false;
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

  bfs(0, v, d, m, n);

  for (int i = 0; i < n; i++) {
    cout << i + 1 << ' ' << d[i] << endl;
  }

  // Deallocate memory
  for (int i = 0; i < n; i++) {
    delete[] m[i];
  }
  delete[] m;
  delete[] d;
  delete[] v;

  return 0;
}