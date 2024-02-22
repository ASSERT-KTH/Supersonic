#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#define FOR(i, a, b) for (long long i = (a); i < (b); i++)
#define REP(i, N) for (long long i = 0; i < (N); i++)
#define ALL(s) (s).begin(), (s).end()
#define fi first
#define se second
#define PI acos(-1.0)
#define INF 1e9 + 7
#define MOD 1e9 + 7
#define EPS 1e-10
typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> V;
string s;
int n;
int y, x, M[9][9];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
inline void solve(int y, int x) {
  stack<pair<int, int>> s;
  s.push(make_pair(y, x));
  while (!s.empty()) {
    int cx = s.top().first;
    int cy = s.top().second;
    s.pop();
    M[cx][cy] = 0;
    for (int i = 0; i < 4; i++) {
      for (int j = 1; j <= 3; j++) {
        int nx = cx + dx[i] * j;
        int ny = cy + dy[i] * j;
        if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && M[nx][ny] == 1)
          s.push(make_pair(nx, ny));
      }
    }
  }
}
int main() {
  cin >> n;
  REP(i, n) {
    REP(j, 8) {
      cin >> s;
      REP(k, 8) { M[j][k] = s[k] - '0'; }
    }
    cin >> x >> y;
    solve(y - 1, x - 1);
    cout << "Data " << i + 1 << ":" << endl;
    REP(j, 8) {
      REP(k, 8) { cout << M[j][k]; }
      cout << endl;
    }
  }
  return 0;
}