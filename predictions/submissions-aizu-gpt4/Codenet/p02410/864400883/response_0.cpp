#include <iostream>
#include <vector>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  vector<int> b(m);
  for (auto& row : a) {
    for (auto& val : row) {
      cin >> val;
    }
  }
  for (auto& val : b) {
    cin >> val;
  }
  for (const auto& row : a) {
    int c = 0;
    for (int j = 0; j < m; ++j) {
      c += row[j] * b[j];
    }
    cout << c << '\n';
  }
  return 0;
}