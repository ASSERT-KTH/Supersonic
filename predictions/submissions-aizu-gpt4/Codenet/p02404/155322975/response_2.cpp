#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int H, W;
  while (cin >> H >> W && (H || W)) {
    vector<string> matrix(H, string(W, '.'));
    fill(matrix.front().begin(), matrix.front().end(), '#');
    fill(matrix.back().begin(), matrix.back().end(), '#');
    for(auto &row : matrix) {
      row.front() = row.back() = '#';
    }
    for(const auto &row : matrix){
      cout << row << "\n";
    }
    cout << "\n";
  }
  return 0;
}