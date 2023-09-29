#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> C(102, vector<int>(102));
stack<pair<int, int>> s;

void meiro(int W, int H, int c) {
  s.push({W, H});

  while (!s.empty()) {
    pair<int, int> p = s.top();
    s.pop();

    if (p.first < 0 || p.second < 0 || p.first >= 102 || p.second >= 102 || C[p.first][p.second] != c)
      continue;

    C[p.first][p.second] = -1;
    s.push({p.first - 1, p.second});
    s.push({p.first, p.second + 1});
    s.push({p.first + 1, p.second});
    s.push({p.first, p.second - 1});
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (1) {
    int w, h;
    cin >> w >> h;
    if (w == 0 && h == 0)
      break;

    for (auto &row : C)
      fill(row.begin(), row.end(), 10);

    int xs, ys, xg, yg;
    cin >> xs >> ys >> xg >> yg;
    int n;
    cin >> n;
    int c, d, x, y;

    for (int i = 0; i < n; i++) {
      cin >> c >> d >> x >> y;
      for (int j = x; j < x + (d == 0 ? 4 : 2); j++)
        fill(C[j].begin() + y, C[j].begin() + y + (d == 0 ? 2 : 4), c);
    }

    meiro(xs, ys, C[xs][ys]);

    cout << (C[xg][yg] == -1 ? "OK" : "NG") << "\n";
  }
  return 0;
}