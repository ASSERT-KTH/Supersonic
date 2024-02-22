#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

struct Queue {
  static const int SIZE = 210000;
  int arr[SIZE];
  int front, rear;

  Queue() {
    front = rear = 0;
  }

  void push(int value) {
    arr[rear] = value;
    rear = (rear + 1) % SIZE;
  }

  int pop() {
    int value = arr[front];
    front = (front + 1) % SIZE;
    return value;
  }

  bool empty() {
    return front == rear;
  }
};

int main() {
  int n, m, q;
  cin >> n >> m >> q;

  vector<vector<int>> graph(n + 1);
  vector<int> dist(n + 1, 999999);
  vector<int> T(n + 1, 0);
  vector<vector<int>> y(n + 1);
  vector<bool> visited(n + 1, false);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  dist[1] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, 1});

  while (!pq.empty()) {
    int d = pq.top().first;
    int u = pq.top().second;
    pq.pop();

    if (d > dist[u]) {
      continue;
    }

    for (int v : graph[u]) {
      if (dist[v] > dist[u] + 1) {
        dist[v] = dist[u] + 1;
        pq.push({dist[v], v});
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j : graph[i]) {
      if (dist[i] < dist[j]) {
        y[i].push_back(j);
        T[j]++;
      }
    }
  }

  int cnt = 0;
  for (int i = 0; i < q; i++) {
    int c;
    cin >> c;
    c--;

    Queue Q1;
    int ss = -1;
    if (dist[a[c]] < dist[b[c]]) {
      ss = b[c];
    }
    else if (dist[a[c]] > dist[b[c]]) {
      ss = a[c];
    }

    if (ss >= 1 && !visited[ss]) {
      Q1.push(ss);
      while (!Q1.empty()) {
        int a1 = Q1.pop();
        if (visited[a1]) {
          continue;
        }
        visited[a1] = true;
        cnt++;

        for (int j : y[a1]) {
          if (!visited[j]) {
            Q1.push(j);
          }
        }
      }
    }
    cout << cnt << endl;
  }

  return 0;
}