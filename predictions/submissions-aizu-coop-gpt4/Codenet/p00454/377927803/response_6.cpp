#include <bitset>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define rep(i, x) for (int i = 0; i < (int)(x); ++i)
#define PB push_back
#define MP make_pair
#define all(a) a.begin(), a.end()
#define omajinai ios::sync_with_stdio(false); cin.tie(0)

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vpii = vector<pair<int, int>>;
using vb = vector<bitset<6007>>; // Change to bitset

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int w, h;
int n;
int x1[1005], x2[1005];
int y1[1005], y2[1005];
vb fld; // Change to bitset vector

int compress(int *x1, int *x2, int w) {
  vi xs;
  rep(i, n) {
    for (int d = -1; d <= 1; ++d) {
      int tx1 = x1[i] + d, tx2 = x2[i] + d;
      if (0 <= tx1 && tx1 <= w)
        xs.PB(tx1);
      if (0 <= tx2 && tx2 <= w)
        xs.PB(tx2);
    }
  }
  sort(all(xs));
  xs.erase(unique(all(xs)), end(xs));
  rep(i, n) {
    x1[i] = lower_bound(all(xs), x1[i]) - begin(xs);
    x2[i] = lower_bound(all(xs), x2[i]) - begin(xs);
  }
  return xs.size();
}

int main() {
  omajinai;
  while (cin >> w >> h, w) {
    cin >> n;
    fld = vb(h + 1); // Initialize bitset vector
    rep(i, n) { cin >> x1[i] >> y1[i] >> x2[i] >> y2[i]; }
    w = compress(x1, x2, w);
    h = compress(y1, y2, h);
    rep(i, n) {
      for (int y = y1[i]; y <= y2[i] - 1; ++y) {
        for (int x = x1[i]; x <= x2[i] - 1; ++x) {
          fld[y][x] = true;
        }
      }
    }
    int ans = 0;
    rep(y, h - 1) rep(x, w - 1) {
      if (fld[y][x])
        continue;
      ans++;
      queue<pair<int, int>> q;
      q.push(MP(y, x));
      while (q.size()) {
        pair<int, int> p = q.front();
        q.pop();
        rep(i, 4) {
          int ny = p.first + dy[i], nx = p.second + dx[i];
          if (ny < 0 || ny >= h - 1 || nx < 0 || nx >= w - 1 || fld[ny][nx])
            continue;
          fld[ny][nx] = true;
          q.push(MP(ny, nx));
        }
      }
    }
    cout << ans << endl;
  }
}