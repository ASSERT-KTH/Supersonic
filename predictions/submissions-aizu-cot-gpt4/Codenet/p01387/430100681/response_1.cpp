#include <bits/stdc++.h>
using namespace std;

// ... (rest of the code)

CentroidPathDecomposition::Centroid::inline pair<const int&, const int&> Up() const { return make_pair(ParIndex, ParDepth); }

RandomizedBinarySearchTree<Key>::Node* RandomizedBinarySearchTree<Key>::alloc(const Key &key) { return &(pool[++ptr] = Node(key)); }

void CentroidPathDecomposition::BuildPath() {
  stack<pair<int, int>> s;
  Centroids.emplace_back(-1, -1, 0);
  s.emplace(0, -1);
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
                               Centroids[TreeIndex[p.first]].Deep + 1);
      }
      s.emplace(to, p.first);
    }
    Centroids[TreeIndex[p.first]].node.emplace_back(p.first);
  }
}

// ... (rest of the code)