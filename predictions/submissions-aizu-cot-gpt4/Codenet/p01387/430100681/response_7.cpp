#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <functional>
#include <cstdio>

using namespace std;

// Rest of the code remains the same

void dump(Node *r, typename vector<Key>::iterator &it) {
  if (!r)
    return;
  r = propagete(r);
  dump(r->l, it);
  *it++ = r->key;  // Prefix increment
  dump(r->r, it);
}

vector<Key> dump(Node *r) {
  vector<Key> v((size_t)count(r));
  auto it = v.begin();  // Store the result of begin
  dump(r, it);
  return v;
}

// Rest of the code remains the same

CentroidPathDecomposition(int SZ) {
  graph.reserve(SZ);  // Reserve memory for vectors
  SubTreeSize.assign(SZ, -1);
  NextPath.reserve(SZ);
  TreeIndex.reserve(SZ);
  TreeDepth.reserve(SZ);
}

// Rest of the code remains the same

void BuildPath() {
  stack<pair<int, int>> s;
  Centroids.emplace_back(-1, -1, 0);  // Use emplace_back
  s.emplace(0, -1);  // Use emplace
  TreeIndex[0] = 0;
  while (!s.empty()) {
    auto p = s.top();
    s.pop();
    TreeDepth[p.first] = (int)Centroids[TreeIndex[p.first]].size();
    for (auto &to : graph[p.first]) {
      if (p.second == to)
        continue;
      if (to == NextPath[p.first]) {
        TreeIndex[to] = TreeIndex[p.first];
      } else {
        TreeIndex[to] = (int)Centroids.size();
        Centroids.emplace_back(TreeIndex[p.first], TreeDepth[p.first],
                             Centroids[TreeIndex[p.first]].Deep + 1);  // Use emplace_back
      }
      s.emplace(to, p.first);  // Use emplace
    }
    Centroids[TreeIndex[p.first]].node.emplace_back(p.first);  // Use emplace_back
  }
}

// Rest of the code remains the same