#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <functional>

struct CentroidPathDecomposition {
  struct Centroid {
    int ParIndex, ParDepth, Deep;
    std::vector<int> node;
    Centroid(int idx, int dep, int deep)