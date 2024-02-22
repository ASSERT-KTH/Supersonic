// (Same includes as before)
#include <stack>
using namespace std;

// (Same variable declarations as before)

// Change set to vector
vector<unsigned long long> memo;

// Change bitset to vector
vector<bool> visited;

// (Same make_graph function as before)

// Change to iterative version of reachability
void reachability(const int &from, vector<bool> &visited) {
  stack<int> s;
  s.push(from);
  while (!s.empty()) {
    int u = s.top();
    s.pop();
    if (!visited[u]) {
      visited[u] = true;
      for (const auto &v : edge[u]) {
        if (!visited[v]) {
          s.push(v);
        }
      }
    }
  }
}

// (Same cut_vertex function as before)

// Change dfs to iterative version
bool dfs(const int &start, int from) {
  stack<int> s;
  s.push(from);
  while (!s.empty()) {
    int u = s.top();
    s.pop();
    if (!visited[u]) {
      visited[u] = true;
      for (const auto &v : edge[u]) {
        if (v == start && visited.count() == size)
          return true;
        if (!visited[v]) {
          s.push(v);
        }
      }
    }
  }
  return false;
}

// (Same solve and main functions as before)