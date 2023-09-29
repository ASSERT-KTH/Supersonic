#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX_T = 3000, MAX_M = 300;
int M, start, goal, dice[6], *N;
bool isPositionValid(int p) { return 0 <= p && p < M; }
vector<int> adj[MAX_M * 2 + 5];
int dist[MAX_M * 2 + 5];
bool vis[MAX_M * 2 + 5];
void bfs(int start) {
    queue<int> q;
    q.push(start);
    vis[start] = true;
    dist[start] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (!vis[v]) {
                vis[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}
int main() {
  cin >> M;
  for (int r = 0; r < 6; r++)
    cin >> dice[r];
  cin >> start >> goal;
  start--, goal--;
  N = new int[M];
  for (int m = 0; m < M; m++)
    cin >> N[m];
  for (int i = 0; i < M; i++) {
      for (int j = 1; j <= 6; j++) {
          int nxt = i + j + N[i];
          if (nxt < M) {
              adj[i].push_back(nxt);
          } else {
              adj[i].push_back(nxt + M);
          }
      }
      for (int j = 1; j <= 6; j++) {
          int nxt = i - j + N[i];
          if (nxt >= 0) {
              adj[i+M].push_back(nxt+M);
          } else {
              adj[i+M].push_back(nxt);
          }
      }
  }
  for (int i = 0; i < 2*M; i++) {
      vis[i] = false;
      dist[i] = MAX_T + 1;
  }
  bfs(start);
  int position = start;
  for (int t = 0; t < MAX_T; t++) {
    if (position == goal)
      break;
    int r;
    cin >> r;
    int d = dice[r - 1];
    int newpos = position + d + N[position];
    if (newpos < M) {
        if (dist[newpos] < MAX_T) {
            cout << 1 << endl;
            position = newpos;
            continue;
        }
    } else {
        newpos += M;
        if (dist[newpos] < MAX_T) {
            cout << 1 << endl;
            position = newpos - M;
            continue;
        }
    }
    newpos = position - d + N[position];
    if (newpos >= 0) {
        if (dist[newpos+M] < MAX_T) {
            cout << -1 << endl;
            position = newpos;
            continue;
        }
    } else {
        newpos += M;
        if (dist[newpos+M] < MAX_T) {
            cout << -1 << endl;
            position = newpos - M;
            continue;
        }
    }
    cout << 0 << endl;
  }
  delete[] N;
  return 0;
}