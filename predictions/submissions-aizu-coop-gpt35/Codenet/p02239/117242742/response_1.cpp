#include <iostream>
#include <vector>
using namespace std;

class Queue {
private:
  int* arr;
  int front;
  int rear;
  int capacity;

public:
  Queue(int capacity) {
    this->capacity = capacity;
    arr = new int[capacity];
    front = 0;
    rear = -1;
  }

  void push(int x) {
    arr[++rear] = x;
  }

  int pop() {
    return arr[front++];
  }

  bool empty() {
    return front > rear;
  }

  bool full() {
    return rear == capacity - 1;
  }
};

int main() {
  int n;
  cin >> n;

  vector<vector<int>> adj(n);
  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;
    adj[u - 1].resize(k);
    for (int j = 0; j < k; j++) {
      cin >> adj[u - 1][j];
    }
  }

  vector<int> d(n, -1);
  vector<bool> v(n, false);

  v[0] = true;
  d[0] = 0;
  Queue q(n);
  q.push(0);

  while (!q.empty()) {
    int u = q.pop();
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i] - 1;
      if (!v[v]) {
        d[v] = d[u] + 1;
        v[v] = true;
        q.push(v);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << i + 1 << ' ' << d[i] << endl;
  }

  return 0;
}