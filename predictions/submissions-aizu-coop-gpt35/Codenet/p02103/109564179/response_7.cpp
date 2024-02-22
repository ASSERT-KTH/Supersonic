#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int n, m, k;
vector<int> obstacles; // Replace the map with a vector to store obstacle positions
int cost[100001];
int dx[] = {-2, -1, 0, 1, 2}; // Possible x offsets for BFS
int dy[] = {-2, -1, 0, 1, 2}; // Possible y offsets for BFS

int bfs() {
  queue<int> que;
  queue<int> que2;
  bool flag = false;
  memset(cost, -1, sizeof(cost));
  for (int i = 1; i <= m - 1; i++) {
    int val = i * n;
    if (binary_search(obstacles.begin(), obstacles.end(), val)) { // Use binary search to check if obstacle exists
      que.push(val);
      cost[val] = 0;
    }
  }
  // ... rest of the code
}

// ... Similar optimizations for bfs2(), bfs3(), and bfs4()

int main(void) {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < k; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    obstacles.push_back(y * n + x); // Store obstacle positions directly in the vector
  }
  sort(obstacles.begin(), obstacles.end()); // Sort the vector for binary search
  // ... rest of the code
}