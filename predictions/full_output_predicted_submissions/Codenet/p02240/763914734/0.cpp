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
    V = new vector<int>[n];
    num_of_each = new int[n];
    group = new int[n];
    for (int i = 0; i < n; i++) {
      num_of_each[i] = 0;
      group[i] = 0;
    }
    group_number = 1;
  }
  void push(int s, int t) {
    V[s].push_back(t);
    V[t].push_back(s);
    num_of_each[s]++;
    num_of_each[t]++;
  }
  void makeGroup() {
    int node, i;
    queue<int> Q;
    Q.push(0);
    group[0] = 1;
    while (true) {
      while (!Q.empty()) {
        node = Q.front();
        Q.pop();
        if (num_of_each[node] > 0) {
          for (int k = 0; k < num_of_each[node]; k++) {
            if (group[V[node][k]] == 0) {
              group[V[node][k]] = group[node];
              Q.push(V[node][k]);
            }
          }
        }
  