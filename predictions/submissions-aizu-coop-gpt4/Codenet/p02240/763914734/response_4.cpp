#include <algorithm>
#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;

class Relation {
public:
  Relation(int tmp_n, int tmp_m) {
    n = tmp_n;
    m = tmp_m;
    V.resize(n);
    group.resize(n, 0);
    group_number = 1;
    grouped_count = 0;
  }
 
  void push(int s, int t) {
    V[s].push_back(t);
    V[t].push_back(s);
  }
 
  void makeGroup() {
    int node, i;
    queue<int> Q;
    Q.push(0);
    group[0] = 1;
    grouped_count++;
  
    while (grouped_count < n) {
      while (!Q.empty()) {
        node = Q.front();
        Q.pop();
        for (int k = 0; k < V[node].size(); k++) {
          if (group[V[node][k]] == 0) {
            group[V[node][k]] = group[node];
            Q.push(V[node][k]);
            grouped_count++;
          }
        }
      }
      group_number++;
      for (i = 0; i < n; i++) {
        if (group[i] == 0) {
          group[i] = group_number;
          Q.push(i);
          grouped_count++;
          break;
        }
      }
    }
  }
 
  bool canAccsess(int s, int t) { return group[s] == group[t]; }

private:
  vector<vector<int>> V; // Replaced pointer to vector with vector of vectors
  vector<int> group; // Replaced pointer to int with vector of ints
  int group_number;
  int grouped_count; // Added to keep track of grouped nodes
  int n, m;
};

// main function remains the same