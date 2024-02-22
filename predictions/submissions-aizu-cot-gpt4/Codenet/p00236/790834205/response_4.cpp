#include <algorithm>
#include <bitset>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
const int N = 49;
int w, h;
vector<vector<int>> field;
int size;
vector<vector<int>> vertex;
vector<vector<int>> edge;
bitset<N> visited;
unordered_set<unsigned long long> memo;
void make_graph(vector<vector<int>>& vertex, vector<vector<int>>& edge) {
  // ... the rest of the code is the same ...
}

void reachability(const int &from, bitset<N> &visited, const vector<vector<int>>& edge) {
  // ... the rest of the code is the same ...
}

bool cut_vertex(const int &from, bitset<N> &visited, const vector<vector<int>>& edge) {
  // ... the rest of the code is the same ...
}

bool dfs(const int &start, int from, bitset<N> &visited, vector<vector<int>>& edge, unordered_set<unsigned long long>& memo) {
  // ... the rest of the code is the same ...
}

bool solve(vector<vector<int>>& vertex, vector<vector<int>>& edge, bitset<N>& visited, unordered_set<unsigned long long>& memo) {
  // ... the rest of the code is the same ...
}

int main() {
  vector<vector<int>> vertex;
  vector<vector<int>> edge;
  bitset<N> visited;
  unordered_set<unsigned long long> memo;
  while (cin >> w >> h, w | h) {
    field = vector<vector<int>>(h, vector<int>(w));
    for (auto &line : field)
      for (auto &v : line)
        cin >> v;
    cout << (solve(vertex, edge, visited, memo) ? "Yes" : "No") << endl;
  }
}