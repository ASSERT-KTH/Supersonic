#include <algorithm>
#include <iostream>
#include <vector>
#define INF 1 << 28
using namespace std;
vector<int> p;
vector<int> memo(1000001, 0);
vector<int> memo2(1000001, 0);
void solve(int n) {
  memo[0] = 0;
  for (int i = 1; i <= n; i++) {
    int ans = INF;
    for (int j = 0; p[j] <= i; j++)
      ans = min(ans, memo[i - p[j]] + 1);
    memo[i] = ans;
  }
}
void solve2(int n) {
  memo2[0] = 0;
  for (int i = 1; i <= n; i++) {
    int ans = INF;
    for (int j = 0; p[j] <= i; j++) {
      if (p[j] % 2 == 0)
        continue;
      ans = min(ans, memo2[i - p[j]] + 1);
    }
    memo2[i] = ans;
  }
}
int main() {
  int n;
  for (int i = 0; i*i*(i + 1)*(i + 1)/36 <= 1000000; i++){
    if (i*(i + 1)*(i + 2)/6 % 2 != 0) 
        p.push_back(i * (i + 1) * (i + 2) / 6);
  }
  solve(1000000);
  solve2(1000000);
  while (cin >> n, n)
    cout << memo[n] << " " << memo2[n] << endl;
}