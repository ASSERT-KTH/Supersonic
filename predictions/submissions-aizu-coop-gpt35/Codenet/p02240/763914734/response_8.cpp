#include <algorithm>
#include <iostream>
#include <vector>
#include <array>

class Relation {
public:
  Relation(int tmp_n, int tmp_m) {
    n = tmp_n;
    m = tmp_m;
    V.resize(n);
    num_of_each.fill(0);
    group.resize(n);
    group_number = 1;
  }
  void push(int s, int t) {
    V[s].push_back(t);
    V[t].push_back(s);
    num_of_each[s]++;
    num_of_each[t]++;
  }
  void findStronglyConnectedComponents() {
    std::vector<int> low(n);
    std::vector<bool> inStack(n);
    std::vector<int> stack;
    std::vector<int> index(n);
    int currentIndex = 0;
    for (int i = 0; i < n; i++) {
      if (index[i] == 0) {
        tarjanDFS(i, low, inStack, stack, index, currentIndex);
      }
    }
  }
  bool canAccess(int s, int t) { return group[s] == group[t]; }

private:
  void tarjanDFS(int node, std::vector<int>& low, std::vector<bool>& inStack, std::vector<int>& stack, std::vector<int>& index, int& currentIndex) {
    index[node] = ++currentIndex;
    low[node] = currentIndex;
    stack.push_back(node);
    inStack[node] = true;

    for (int k = 0; k < num_of_each[node]; k++) {
      int neighbor = V[node][k];
      if (index[neighbor] == 0) {
        tarjanDFS(neighbor, low, inStack, stack, index, currentIndex);
        low[node] = std::min(low[node], low[neighbor]);
      } else if (inStack[neighbor]) {
        low[node] = std::min(low[node], index[neighbor]);
      }
    }

    if (low[node] == index[node]) {
      while (true) {
        int top = stack.back();
        stack.pop_back();
        inStack[top] = false;
        group[top] = group_number;
        if (top == node) {
          break;
        }
      }
      group_number++;
    }
  }

  std::vector<std::vector<int>> V;
  std::array<int, n> num_of_each;
  std::array<int, n> group;
  int group_number;
  int n, m;
};

int main() {
  int n, m, s, t, q;
  std::cin >> n >> m;
  Relation relation(n, m);
  for (int i = 0; i < m; i++) {
    std::cin >> s >> t;
    relation.push(s, t);
  }
  relation.findStronglyConnectedComponents();
  std::cin >> q;
  for (int i = 0; i < q; i++) {
    std::cin >> s >> t;
    if (relation.canAccess(s, t)) {
      std::cout << "yes\n";
    } else {
      std::cout << "no\n";
    }
  }
  return 0;
}