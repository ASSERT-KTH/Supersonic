#include <iostream>
#include <vector>
using namespace std;

vector<int> N;
int n;
vector<vector<int>> memo;

bool solve(int i, int m) {
  if (m == 0) return true;
  if (i == n || m < 0) return false;
  
  if (memo[i][m] != -1) {
    return memo[i][m];
  }
  
  return memo[i][m] = solve(i + 1, m - N[i]) || solve(i + 1, m);
}

int main() {
  int t;
  cin >> n;

  N.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> N[i];
  }

  cin >> t;
  memo.resize(n, vector<int>(t + 1, -1));

  for (int i = 0; i < t; i++) {
    int p;
    cin >> p;
    if (solve(0, p)) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
}