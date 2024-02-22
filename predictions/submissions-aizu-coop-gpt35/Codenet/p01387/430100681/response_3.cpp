#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct CentroidPathDecomposition {
  struct Centroid {
    int ParIndex, ParDepth, Deep;
    vector<int> node;
    Centroid(int idx, int dep, int deep)
        : ParIndex(idx), ParDepth(dep), Deep(deep) {}
    inline size_t size() { return (node.size()); }
    inline int &operator[](int k) { return (node[k]); }
    inline pair<int, int> Up() { return (make_pair(ParIndex, ParDepth)); }
  };
  vector<vector<int>> graph;
  vector<int> SubTreeSize, NextPath;
  vector<int> TreeIndex, TreeDepth;
  vector<Centroid> Centroids;
  void BuildSubTreeSize() {
    vector<pair<int, int>> s;
    s.emplace_back(0, -1);
    while (!s.empty()) {
      auto p = s.back();
      s.pop_back();