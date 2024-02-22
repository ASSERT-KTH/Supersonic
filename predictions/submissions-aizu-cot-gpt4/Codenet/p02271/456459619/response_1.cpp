#include <iostream>
#include <vector>
using namespace std;

vector<int> N;
int n;

bool solve(int i, int m) {
  if(m == 0) {
    return true;
  }
  if(i == n || m < 0) {
    return false;
  }
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
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }
  return 0;
}