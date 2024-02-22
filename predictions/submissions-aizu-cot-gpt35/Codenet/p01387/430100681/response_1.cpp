#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

struct CentroidPathDecomposition {
  struct Centroid {
    int ParIndex, ParDepth, Deep;
    std::vector<int> node;
    Centroid(int idx, int dep, int deep)
        : ParIndex(idx), ParDepth(dep), Deep(deep) {}
    inline size_t size() { return node.size(); }
    inline int &operator[](int k) { return node[k]; }
    inline std::pair<int, int> Up() { return std::make_pair(ParIndex, ParDepth); }
  };

  std::vector<std::vector<int>> graph;
  std::vector<int> SubTreeSize, NextPath;
  std::vector<int> TreeIndex, TreeDepth;
  std::vector<Centroid> Centroids;

  void BuildSubTreeSize() {
    std::stack<std::pair<int, int>> s;
    s.emplace(0, -1);
    while (!s.empty()) {
      auto p = s.top();
      s.pop();
      if (~SubTreeSize[p.first]) {
        NextPath[p.first] = -1;
        for (auto &to : graph[p.first]) {
          if (p.second == to)
            continue;
          SubTreeSize[p.first] += SubTreeSize[to];
          if (NextPath[p.first] == -1 ||
              SubTreeSize[NextPath[p.first]] < SubTreeSize[to]) {
            NextPath[p.first] = to;
          }
        }
      } else {
        s.push(p);
        SubTreeSize[p.first] = 1;
        for (auto &to : graph[p.first]) {
          if (p.second != to)
            s.emplace(to, p.first);
        }
      }
    }
  }

  void BuildPath() {
    std::stack<std::pair<int, int>> s;
    Centroids.emplace_back(-1, -1, 0);
    s.emplace(0, -1);
    TreeIndex[0] = 0;
    while (!s.empty()) {
      auto p = s.top();
      s.pop();
      TreeDepth[p.first] = (int)Centroids[TreeIndex[p.first]].size();