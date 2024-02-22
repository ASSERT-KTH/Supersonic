#include <queue>

void bfs(int s, int n) {
  int** m = new int*[n];
  for (int i = 0; i < n; i++) {
    m[i] = new int[n];
    for (int j = 0; j < n; j++) {
      m[i][j] = 0;
    }
  }

  int* d = new int[n];
  int* v = new int[n];
  for (int i = 0; i < n; i++) {
    d[i] = -1;
    v[i] = 0;
  }

  v[s] = 1;
  d[s] = 0;
  std::queue<int> q;
  q.push(s);

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < n; i++) {
      if (m[u][i] && !v[i]) {
        d[i] = d[u] + 1;
        v[i] = 1;
        q.push(i);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    delete[] m[i];
  }
  delete[] m;
  delete[] d;
  delete[] v;
}

int main() {
  int n;
  std::cin >> n;

  bfs(0, n);

  for (int i = 0; i < n; i++) {
    std::cout << i << ' ' << d[i] << std::endl;
  }

  return 0;
}