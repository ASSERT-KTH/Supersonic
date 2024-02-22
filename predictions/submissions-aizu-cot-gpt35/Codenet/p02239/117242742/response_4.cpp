#include <iostream>
using namespace std;

int** m;
int n;
bool* v;
int* d;

void bfs(int s) {
  v[s] = true;
  d[s] = 0;
  int visitedCount = 1;
  int* queue = new int[n];
  int front = 0;
  int rear = 0;
  queue[rear++] = s;

  while (front != rear) {
    int u = queue[front++];
    for (int i = 0; i < n; i++) {
      if (m[u][i] && !v[i]) {
        d[i] = d[u] + 1;
        v[i] = true;
        queue[rear++] = i;
        visitedCount++;
      }
    }
    if (visitedCount == n) {
      break;
    }
  }

  delete[] queue;
}

int main() {
  cin >> n;
  m = new int*[n];
  v = new bool[n];
  d = new int[n];

  for (int i = 0; i < n; i++) {
    m[i] = new int[n];
    v[i] = false;
    d[i] = -1;
    for (int j = 0; j < n; j++) {
      m[i][j] = 0;
    }
  }

  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;
    while (k--) {
      int v;
      cin >> v;
      m[u - 1][v - 1] = 1;
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