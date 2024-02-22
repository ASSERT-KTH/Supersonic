#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool m[105][105]; // Change int array to bool array
vector<int> v(105), d(105); // Change C-style arrays to vectors
int n;

void bfs(int s) {
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
  ios::sync_with_stdio(false); // Optimize I/O operations
  cin.tie(NULL); // Untie cin from cout

  cin >> n;
  
  for (int i = 0; i < n; i++)
    d[i] = -1;
  
  for (int i = 0; i < n; i++) {
    int u, v, k;
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      cin >> v;
      m[u - 1][v - 1] = true;
    }
  }

  bfs(0);
  
  for (int i = 0; i < n; i++)
    cout << i + 1 << ' ' << d[i] << '\n'; // Use '\n' instead of endl
  
  return 0;
}