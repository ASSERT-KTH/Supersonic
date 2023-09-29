#include <cstdio>
#include <vector>
using namespace std;

vector<int> N;

bool solve(int i, int m) {
  if (i == N.size()) {
    return m == 0;
  }
  return solve(i + 1, m - N[i]) || solve(i + 1, m);
}

int main() {
  int n, t;
  scanf("%d", &n);
  N.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &N[i]);
  }
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int p;
    scanf("%d", &p);
    if (solve(0, p)) {
      puts("yes");
    } else {
      puts("no");
    }
  }
  return 0;
}