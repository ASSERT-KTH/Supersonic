#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <stack>

// ... All the class and function definitions remain the same ...

void dfs(int index, int parentIndex, OrderedMultiSet<int>::Node *parentSet) {
  parent[index] = parentIndex;
  tree.insert_key(parentSet, X[index]);
  nodes[index] = parentSet;
  for (auto &to : g[index])
    if (to != parentIndex)
      dfs(to, index, parentSet);
}

int main() {
  std::cin >> N >> Q;
  CentroidPathDecomposition decomposition(N);
  std::vector<int> values;
  for (int i = 0; i < N; i++) {
    std::cin >> X[i];
    values.emplace_back(X[i]);
  }
  std::sort(values.begin(), values.end());
  values.erase(std::unique(values.begin(), values.end()), values.end());

  // ... Rest of the main function remains the same ..
}