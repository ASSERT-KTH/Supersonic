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

// BFS instead of recursive function
void solve(int y, int x) {
  queue<P> q;
  q.push(P(y, x));
  M[y][x] = 0;
  while (!q.empty()) {
    P p = q.front(); q.pop();
    for (int i = 0; i < 4; i++) {
      for (int j = 1; j <= 3; j++) {
        int ny = p.first + dy[i] * j, nx = p.second + dx[i] * j;
        if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8 && M[ny][nx] == 1) {
          M[ny][nx] = 0;
          q.push(P(ny, nx));
        }
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
}