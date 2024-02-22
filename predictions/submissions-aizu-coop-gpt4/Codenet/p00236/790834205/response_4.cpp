#include <algorithm>
#include <bitset>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
const int N = 49;
int w, h;
vector<vector<int>> field(N, vector<int>(N));
int size;
vector<vector<int>> vertex(N, vector<int>(N));
vector<vector<int>> edge(N * N);
bitset<N> visited;
unordered_set<unsigned long long> memo;

// ... other functions are the same

bool solve() {
  visited.reset();
  make_graph();
  memo.clear();
  for (int y = 0; y < h; ++y)
    for (int x = 0; x < w; ++x)
      if (!field[y][x])
        return dfs(vertex[y][x], vertex[y][x]);
  return false;
}

int main() {
  ios_base::sync_with_stdio(false); // speed up cin/cout
  cin.tie(NULL);
  while (cin >> w >> h, w | h) {
    for (auto &line : field)
      for (auto &v : line)
        cin >> v;
    cout << (solve() ? "Yes" : "No") << '\n';
  }
}