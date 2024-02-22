#include <iostream>
#include <queue>
#include <array>
#include <unordered_set>

class Relation {
public:
  Relation(int tmp_n) {
    n = tmp_n;
    V.resize(n);
    num_of_each.fill(0);
    group.fill(0);
    group_number.fill(0);
  }
  
  void push(int s, int t) {
    V[s].insert(t);
    V[t].insert(s);
    num_of_each[s]++;
    num_of_each[t]++;
  }
  
  void makeGroup() {
    int node, i;
    std::queue<int> Q;
    Q.push(0);
    group[0] = 1;
    
    while (true) {
      while (!Q.empty()) {
        node = Q.front();
        Q.pop();
        if (num_of_each[node] > 0) {
          for (const auto& neighbor : V[node]) {
            if (group[neighbor] == 0) {
              group[neighbor] = group[node];
              Q.push(neighbor);
            }
          }
        }
      }
      
      group_number++;
      
      for (i = 0; i < n; i++) {
        if (group[i] == 0) {
          group[i] = group_number;
          Q.push(i);
          break;
        }
      }
      
      if (i == n)
        break;
    }
  }
  
  bool canAccess(int s, int t) {
    return group[s] == group[t];
  }

private:
  std::vector<std::unordered_set<int>> V;
  std::array<int, 10000> num_of_each;
  std::array<int, 10000> group;
  std::array<int, 10000> group_number;
  int n;
};

int main() {
  int n, s, t, q;
  std::cin >> n;
  Relation relation(n);
  
  for (int i = 0; i < n-1; i++) {
    std::cin >> s >> t;
    relation.push(s, t);
  }
  
  relation.makeGroup();
  
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