#include <iostream>
#include <vector>

using namespace std;

struct MyQueue {
  static const int MAX_SIZE = 1000;
  int arr[MAX_SIZE];
  int front, rear;

  MyQueue() : front(-1), rear(-1) {}

  bool empty() {
    return front == -1;
  }

  void push(int x) {
    if (front == -1) {
      front = rear = 0;
    } else {
      rear = (rear + 1) % MAX_SIZE;
    }
    arr[rear] = x;
  }

  void pop() {
    if (front == rear) {
      front = rear = -1;
    } else {
      front = (front + 1) % MAX_SIZE;
    }
  }

  int frontElement() {
    return arr[front];
  }
};

void bfs(int s, int n, vector<int> adj[], int dist[]) {
  bool visited[n];
  for (int i = 0; i < n; i++) {
    visited[i] = false;
    dist[i] = -1;
  }

  visited[s] = true;
  dist[s] = 0;
  MyQueue q;
  q.push(s);

  while (!q.empty()) {
    int u = q.frontElement();
    q.pop();
    for (int v : adj[u]) {
      if (!visited[v]) {
        dist[v] = dist[u] + 1;
        visited[v] = true;
        q.push(v);
      }
    }
  }
}

int main() {
  int n;
  cin >> n;

  if (n <= 0 || n > 105) {
    cout << "Invalid number of nodes" << endl;
    return 1;
  }

  vector<int> adj[n];
  int dist[n];

  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;

    if (u <= 0 || u > n || k < 0 || k > n) {
      cout << "Invalid input" << endl;
      return 1;
    }

    for (int j = 0; j < k; j++) {
      int v;
      cin >> v;

      if (v <= 0 || v > n) {
        cout << "Invalid input" << endl;
        return 1;
      }

      adj[u - 1].push_back(v - 1);
    }
  }

  bfs(0, n, adj, dist);

  for (int i = 0; i < n; i++) {
    cout << i + 1 << ' ' << dist[i] << endl;
  }

  return 0;
}