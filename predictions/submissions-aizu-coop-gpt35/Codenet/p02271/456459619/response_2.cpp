#include <iostream>
#include <vector>
using namespace std;

int *N;
int n;
vector<vector<bool>> memo;

bool solve(int& i, int& m) {
  if (i == n) {
    return m == 0;
  }
  
  if (memo[i][m]) {
    return memo[i][m];
  }
  
  bool result = solve(++i, m - N[i]) || solve(i, m);
  memo[i][m] = result;
  
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> n;
  N = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> N[i];
  }
  cin >> t;
  memo.assign(n + 1, vector<bool>(t + 1, false));
  for (int i = 0; i < t; i++) {
    int p;
    cin >> p;
    int index = 0;
    if (solve(index, p)) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
  
  delete[] N;
  return 0;
}