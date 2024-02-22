#include <algorithm>
#include <iostream>
#include <string>
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
int y, x, M[8][8];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void solve(int y, int x) {
  stack<pair<int, int>> st;
  st.push(make_pair(y, x));
  while (!st.empty()) {
    int cy = st.top().first;
    int cx = st.top().second;
    st.pop();
    M[cy][cx] = 0;
    for (int i = 0; i < 4; i++) {
      for (int j = 1; j <= 3; j++) {
        int ny = cy + dy[i] * j;
        int nx = cx + dx[i] * j;
        if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8 && M[ny][nx] == 1) {
          st.push(make_pair(ny, nx));
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
    cout << "Data " << i + 1 << ":\n";
    REP(j, 8) {
      REP(k, 8) { cout << M[j][k]; }
      cout << '\n';
    }
  }
}