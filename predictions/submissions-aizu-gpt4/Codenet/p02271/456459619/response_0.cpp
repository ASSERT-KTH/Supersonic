#include <vector>
#include <iostream>
using namespace std;

vector<int> N;
int n;

bool solve(int i, int m) {
  if (m == 0) return true;
  if (i >= n) return false;
  return solve(i + 1, m - N[i]) || solve(i + 1, m);
}

int main() {
  int t;
  cin >> n;
  N.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> N[i];
  }
  cin >> t;
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