#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Circle {
  int x, y, r, c;  
};

bool ok(const Circle& a, const Circle& b) {
  int dist = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
  int sum = (a.r + b.r) * (a.r + b.r);
  return dist >= sum;
}

int dfs(vector<Circle>& circles, vector<bool>& memo, int bit) {
  memo[bit] = true;
  int ret = circles.size();
  for (int i = 0; i < circles.size(); i++)
    if (bit & (1 << i))
      ret--;
  for (int i = 0; i < circles.size(); i++) {
    if (!(bit & (1 << i)) || !ok(circles[i], circles[bit]))
      continue;
    for (int j = i + 1; j < circles.size(); j++) {
      if (!(bit & (1 << j)) || circles[i].c != circles[j].c)
        continue;
      int to_bit = bit ^ (1 << i) ^ (1 << j);
      if (ok(circles[j], circles[bit]) && !memo[to_bit]) {
        ret = max(ret, dfs(circles, memo, to_bit));
      }
    }
  }
  return ret;
}

void solve(vector<Circle>& circles) {
  vector<bool> memo(1 << circles.size(), false);
  cout << dfs(circles, memo, (1 << circles.size()) - 1) << endl;
}

bool input(vector<Circle>& circles) {
  int n;
  cin >> n;
  if (!n)
    return false;
  circles.resize(n);
  for (int i = 0; i < n; i++)
    cin >> circles[i].x >> circles[i].y >> circles[i].r >> circles[i].c;
  return true;
}

int main() {
  vector<Circle> circles;
  while (input(circles))
    solve(circles);
  return 0;
}